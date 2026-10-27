#include <vector>

int gcd(int a, int b) {
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

inline int bit_length(int x) {
    return x ? 32 - __builtin_clz((unsigned)x) : 0;
}

enum OpFlag : unsigned {
    OP_SUM = 1u << 0,
    OP_MIN = 1u << 1,
    OP_MAX = 1u << 2,
    OP_GCD = 1u << 3,
    OP_ALL = OP_SUM | OP_MIN | OP_MAX | OP_GCD,
};

struct Node {
    long long sum = 0;
    int mi = INT_MAX;
    int mx = INT_MIN;
    int g = 0;
};

template<unsigned OpMask>
inline Node make_node(int x) {
    Node r;
    if constexpr (OpMask & OP_SUM) r.sum = x;
    if constexpr (OpMask & OP_MIN) r.mi  = x;
    if constexpr (OpMask & OP_MAX) r.mx  = x;
    if constexpr (OpMask & OP_GCD) r.g   = std::abs(x);
    return r;
}

template<unsigned OpMask>
inline Node merge_node(const Node& a, const Node& b) {
    Node r;
    if constexpr (OpMask & OP_SUM) r.sum = a.sum + b.sum;
    if constexpr (OpMask & OP_MIN) r.mi  = std::min(a.mi, b.mi);
    if constexpr (OpMask & OP_MAX) r.mx  = std::max(a.mx, b.mx);
    if constexpr (OpMask & OP_GCD) r.g   = std::gcd(a.g, b.g);
    return r;
}

template<unsigned OpMask=OP_MAX>
class ST {
    static_assert(OpMask != 0, "OpMask must contain at least one OpFlag");
    static constexpr bool kIdem = !(OpMask & OP_SUM);

    int n = 0, w = 0;
    std::vector<std::vector<Node>> st;

public:
    explicit ST(const std::vector<int>& a)
        : n((int)a.size()), w(bit_length(n))
    {
        if (n == 0) return;
        st.assign(n, std::vector<Node>(w));
        for (int i = 0; i < n; ++i) {
            st[i][0] = make_node<OpMask>(a[i]);
        }
        for (int j = 1; j < w; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                st[i][j] = merge_node<OpMask>(st[i][j-1], st[i+(1<<(j-1))][j-1]);
            }
        }
    }

    template<unsigned QMask>
    Node query(int l, int r) const {
        static_assert((QMask & ~OpMask) == 0,
                      "QMask must be a subset of OpMask");
        assert(0 <= l && l < r && r <= n);

        if constexpr ((QMask & OP_SUM) == 0) {
            int k = bit_length(r - l) - 1;
            return merge_node<QMask>(st[l][k], st[r - (1<<k)][k]);
        } else {
            Node res;
            bool first = true;
            for (int k = w - 1; k >= 0; --k) {
                if (l + (1 << k) <= r) {
                    if (first) {
                        res = st[l][k];
                        first = false;
                    } else {
                        res = merge_node<QMask>(res, st[l][k]);
                    }
                    l += 1 << k;
                }
            }
            return res;
        }
    }
};