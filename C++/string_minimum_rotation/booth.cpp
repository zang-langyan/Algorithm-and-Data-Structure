#include <string>
#include <algorithm>

std::string min_rot(const std::string& s) {
    std::string ss = s + s;
    int n = s.length();
    int i = 0, j = 1, k = 0;
    while (i < n && j < n && k < n) {
        char a = ss[i + k];
        char b = ss[j + k];
        if (a == b) {
            k += 1;
        } else if (a < b) {
            j += k + 1;
            k = 0;
            if (i == j) {
                j += 1;
            }
        } else {
            i += k + 1;
            k = 0;
            if (i == j) {
                i += 1;
            }
        }
    }
    return ss.substr(std::min(i, j), n);
}