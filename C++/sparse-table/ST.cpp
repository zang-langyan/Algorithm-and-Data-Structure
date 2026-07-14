#include <tuple>
#include <vector>

static int gcd(int a, int b) {
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

static inline int bit_length(int x) {
    return 32 - __builtin_clz(x);
}

using tupleiii = std::tuple<int, int, int>;
tupleiii op(const tupleiii& a, const tupleiii& b) {
    const auto& [mia, mxa, ga] = a;
    const auto& [mib, mxb, gb] = b;
    return {std::min(mia, mib), std::max(mxa, mxb), gcd(ga, gb)};
}

class ST {
private:
    int n;
    int w;
    std::vector<std::vector<std::tuple<int, int, int>>> st;
public:
    ST(const std::vector<int>& a)
        : n(a.size()), w(bit_length(n))
    {
        st = std::vector<std::vector<std::tuple<int, int, int>>>(w, 
            std::vector<std::tuple<int, int, int>>(n));
        for (int i = 0; i < n; ++i) {
            st[0][i] = {a[i], a[i], a[i]};
        }
        for (int i = 1; i < w; ++i) {
            for (int j = 0; j < (n - (1 << i) + 1); ++j) {
                st[i][j] = op(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    
    /** [l, r) 左闭右开 */
    std::tuple<int, int, int> query(int l, int r) {
        int k = bit_length(r - l) - 1;
        return op(st[k][l], st[k][r - (1 << k)]);
    }
};

int main() {

    return 0;
}