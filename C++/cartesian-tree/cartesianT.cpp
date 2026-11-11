#include <bits/stdc++.h>
using namespace std;

/* Max Cartesian Tree */
/* It has heap property (as for father node is always greater/smaller than child nodes) */
/* Its mid-traverse order restore the original array */

/* Consider this problem from codeforces - 2205D */
/*
    We call an array b of length m cool if and only if:
    There exists no index i (1<i<m) such that bi=max({bi−1,bi,bi+1}).

    Simons has an array a of size n. Initially, the array is a permutation.
    He must perform the following operation until the array is cool:

    Choose an index i (1<i<n) such that ai=max({ai−1,ai,ai+1}). 
    Then, he can remove either ai−1 or ai+1 from the array. 
    After removal, a gap appears in the array, and the left and right sides of the gap will be rejoined.

    Find the minimum number of operations for Simons to perform.
*/
void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    
    vi l(n, -1), r(n, -1);
    vi st;
    st.reserve(n);
    for (int i = 0; i < n; ++i) {
        int left = -1;
        while (!st.empty() && a[st.back()] < a[i]) {
            left = st.back();
            st.pop_back();
        }
        if (!st.empty()) {
            r[st.back()] = i;
        }
        l[i] = left;
        st.push_back(i);
    }
    int root = st[0];
    function<int(int)> dfs = [&](int node) -> int {
        if (node == -1) return 0;
        return max(dfs(l[node]), dfs(r[node])) + 1;
    };
    cout << n - dfs(root) << endl;
}
