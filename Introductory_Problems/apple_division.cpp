#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
typedef long long ll;

int main() {
    int n; std::cin >> n;
    std::vector<ll> apples(n);
    for (auto& x: apples) {
        std::cin >> x;
    }
    ll res = LLONG_MAX;
    for (int bitset = 0; bitset < (1 << n); ++bitset) {
        // go through the bitset to see what's included
        ll A = 0, B = 0;
        for (int i = 0; i < n; ++i) {
            int bitmask = (1 << i);
            if (bitset & bitmask) {
                A += apples[i];
            } else {
                B += apples[i];
            }
        }
        res = std::min(res, std::abs(A - B));
    }
    std::cout << res << '\n';

}