#include <vector>


// using a max SegT as an example
class SegT {
private:
  std::vector<int> x;

private:
  void update(int p) {
    x[p] = max(x[p * 2], x[p * 2 + 1]);
  }

  void build(const std::vector<int>& a, int p, int l, int r) {
    if (l == r) {
      x[p] = a[l];
    }

    int mid = l + (r - l) / 2;
    build(a, p * 2, l, mid);
    build(a, p * 2 + 1, mid + 1, r);
    update(p);
  }

public:
  SegT(const std::vector<int>& a) {
    int n = a.size();
    x.resize(4 * n);
    build(a, 1, 0, n - 1);
  }

  int find_first_t(int p, int l, int r, int t) {
    if (x[p] < t) {
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
