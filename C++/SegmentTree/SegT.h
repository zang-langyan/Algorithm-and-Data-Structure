#include <vector>

enum OpFlag : unsigned {
    OP_SUM = 1u << 0,
    OP_MIN = 1u << 1,
    OP_MAX = 1u << 2,
    OP_GCD = 1u << 3,
    OP_ALL = OP_SUM | OP_MIN | OP_MAX | OP_GCD,
};

template<class T>
struct Node {
  T mx, mi, sum, g;
}

template<class T, unsigned OpMask>
inline Node<T> make_node(T x) {
    Node<T> r;
    if constexpr (OpMask & OP_SUM) r.sum = x;
    if constexpr (OpMask & OP_MIN) r.mi  = x;
    if constexpr (OpMask & OP_MAX) r.mx  = x;
    if constexpr (OpMask & OP_GCD) r.g   = std::abs(x);
    return r;
}

template<unsigned OpMask>
inline Node<T> merge_node(const Node<T>& a, const Node<T>& b) {
    Node<T> r;
    if constexpr (OpMask & OP_SUM) r.sum = a.sum + b.sum;
    if constexpr (OpMask & OP_MIN) r.mi  = std::min(a.mi, b.mi);
    if constexpr (OpMask & OP_MAX) r.mx  = std::max(a.mx, b.mx);
    if constexpr (OpMask & OP_GCD) r.g   = std::gcd(a.g, b.g);
    return r;
}

template<class T, unsigned OpMask>
class SegT {
private:
  std::vector<Node<T>> x;
  int n;
private:
  void update(int p) {
    x[p] = merge_node<OpMask>(x[p * 2], x[p * 2 + 1]);
  }

  void build(const std::vector<T>& a, int p, int l, int r) {
    if (l == r) {
      x[p] = make_node<T, OpMask>(a[l]);
      return;
    }

    int mid = l + (r - l) / 2;
    build(a, p * 2, l, mid);
    build(a, p * 2 + 1, mid + 1, r);
    update(p);
  }

  template<unsigned QMask>
  Node _query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
      return x[p];
    }
    int mid = l + (r - l) / 2;
    Node ll, rr, res;
    if (ql <= mid) {
      ll = _query<QMask>(p * 2, l, mid, ql, qr);
      res = ll;
    }
    if (qr > mid) {
      rr = _query<QMask>(p * 2 + 1, mid + 1, r, ql, qr);
      res = rr;
    }
    if (ql <= mid && qr > mid) {
      res = merge_node<QMask>(ll, rr);
    }
    return res;
  }

public:
  explicit SegT(const std::vector<int>& a) {
    n = a.size();
    x.resize(4 * n);
    build(a, 1, 0, n - 1);
  }

  template<unsigned QMask>
  Node query(int ql, int qr) {
    assert(ql <= qr && ql >= 0 && qr < n);
    return _query<QMask>(1, 0, n-1, ql, qr);
  }

  int find_first_t(int p, int l, int r, T t) {
    if (x[p].mx < t) {
      return -1;
    }

    if (l == r) {
      // TODO: maybe some update here
      return l;
    }

    int mid = l + (r - l) / 2;
    // TODO: if the target is finding the last, then one can find the right node first
    int ans = find_first_t(p * 2, l, mid, t);
    if (ans < 0) {
      ans = find_first_t(p * 2 + 1, mid + 1, r, t);
    }
    if (ans >= 0) {
      update(p);
    }
    return ans;
  }
}
