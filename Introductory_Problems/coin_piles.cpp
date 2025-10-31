#include <iostream>

typedef long long ll;

void solve() {
    ll a,b; std::cin >> a >> b;
    ll y = -(a - 2 * b) / 3;
    ll x = (a - y) / 2;
    if (2 * x + y != a || x + 2 * y != b || x < 0 || y < 0) {
        std::cout << "NO" << "\n";
    } else {
        std::cout << "YES" << "\n";
    }
}

int main() {
    int t; std::cin >> t;
    while (t--) {
        solve();
    }
}