#include <bits/stdc++.h>
using namespace std;

int main() {
    vi primes;
    vector<char> is_prime(N+1, true);
    for (int i = 2; i <= N; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (ll j = 1LL * i * i; j <= N; j += i) is_prime[j] = false;
        }
    }
}