#include <iostream>
#include <cmath>

typedef long long ll;
const long long MOD = pow(10,9) + 7;

ll count(ll n) {
    if (n == 1) {
        return 2;
    } else {
        return 2 * (count(n - 1) % MOD);
    }
}


int main() {
    ll n; std::cin >> n;
    const ll res = count(n);
    std::cout << res % MOD << "\n";
}