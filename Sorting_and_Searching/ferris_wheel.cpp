#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> P(n);
    for (auto& p : P) cin >> p;
    int res = 0;
    sort(P.begin(), P.end());
    int l = 0, r = n - 1;
    while (l <= r) {
        if (l == r) { res++; break; }
        if (P[l] + P[r] <= x) { res++; l++; r--; }
        else { res++; r--; }
    }
    cout << res << '\n';
}