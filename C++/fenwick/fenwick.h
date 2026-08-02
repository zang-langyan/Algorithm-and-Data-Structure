#include <vector>
class Fenwick {
    int n;
    std::vector<int> tree;
public:
    Fenwick(int N) : n(N), tree(n+2) {}

    void add(int i, int d = 1) {
        while (i <= n) {
            tree[i] += d;
            i += i & -i;
        }
    }

    int query(int i) {
        int s = 0;
        while (i > 0) {
            s += tree[i];
            i -= i & -i;
        }
        return s;
    }
};