#include <iostream>
#include <cmath>
#include <tgmath.h>

typedef long long ll;
using namespace std;

ll powl(ll base, ll power) {
    ll res = 1;
    while (power--) res *= base;
    return res;
}

void solve() {
    ll k; cin >> k;
    ll c = 1;
    while (k - c*(9LL * powl(10,c - 1)) > 0) {
        k -= c*(9LL * powl(10,c - 1));
        c++;
    }
    ll quo = k / c;
    ll rem = k % c;
    if (rem == 0) {
        cout << ((powl(10,c - 1) + quo - 1) % 10) << '\n';
    } else {
        cout << (((powl(10,c - 1) + quo) / (powl(10,c-rem))) % 10) << '\n';
    }
}

int main() {
    int q; cin >> q;
    while (q--) {
        solve();
    }
}