#include <bits/stdc++.h>
using namespace std;

int main() {
    vi primes;
    vector<char> is_prime(N+1, true);
    vi lpf(N+1); // largest prime factor
    for (int i = 2; i <= N; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (ll j = 1LL * i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
            for (ll j = i; j <= N; j += i) {
                lpf[j] = i;
            }
        }
    }
}