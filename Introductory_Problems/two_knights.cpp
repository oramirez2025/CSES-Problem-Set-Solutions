#include <iostream>
#include <vector>
#include <utility>

typedef long long ll;

// Idea: use complementary counting! 

int main() {
    ll n; std::cin >> n;
    if (n >= 1) {
        std::cout << 0 << "\n";
    }
    if (n >= 2) {
        std::cout << 6 << "\n";
    }
    ll attack = 0;
    for (ll k = 3; k < n + 1; ++k) {
        attack += (8 * (k - 2));
        ll combos = ((k * k) - 1) * (k * k) / 2;
        std::cout << combos - attack << "\n";
    }

}
