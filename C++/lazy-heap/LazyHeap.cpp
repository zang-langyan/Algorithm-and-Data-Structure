#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

template<class T, class Compare = less<T>>
class LazyHeap {
    priority_queue<T, vector<T>, Compare> pq;
    unordered_map<T, int> remove_cnt;
    size_t sz = 0;

    void apply_remove() {
        while (!pq.empty() && remove_cnt[pq.top()] > 0) {
            --remove_cnt[pq.top()];
            pq.pop();
        }
    }

public:
    size_t size() {
        return sz;
    }

    void remove(T x) {
        ++remove_cnt[x];
        --sz;
    }

    T top() {
        apply_remove();
        return pq.top();
    }

    T pop() {
        apply_remove();
        --sz;
        T x = pq.top();
        pq.pop();
        return x;
    }

    void push(T x) {
        pq.push(x);
        ++sz;
    }

    T pushpop(T x) {
        if (sz > 0 && Compare()(x, top())) { /* top() has applied removal already */
            pq.push(x);
            x = pq.top();
            pq.pop();
        }
        return x;
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> ans(n - k + 1);
        LazyHeap<int> mx;
        LazyHeap<int, greater<>> mi;

        for (int i = 0; i < n; ++i) {
            int in = nums[i];
            if (mx.size() == mi.size()) {
                mx.push(mi.pushpop(in));
            } else {
                mi.push(mx.pushpop(in));
            }

            int l = i + 1 - k;
            if (l < 0) {
                continue;
            }

            if (k % 2) { // odd window size
                ans[l] = mx.top();
            } else {
                ans[l] = ((long long) mx.top() + mi.top()) / 2.0;
            }

            int out = nums[l];
            if (out <= mx.top()) {
                mx.remove(out);
                if (mx.size() < mi.size()) {
                    mx.push(mi.pop());
                }
            } else {
                mi.remove(out);
                if (mx.size() > mi.size() + 1) {
                    mi.push(mx.pop());
                }
            }
        }
        return ans;
    }
};