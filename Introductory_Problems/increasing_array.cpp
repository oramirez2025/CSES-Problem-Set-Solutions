#include <iostream> 
#include <vector>
using namespace std;

typedef unsigned long long ull;



int main() {
    int n; cin >> n;
    vector<ull> A(n);
    cin >> A[0];
    ull mx = A[0];
    ull res = 0;
    for (int i = 1; i < n; ++i) {
        cin >> A[i];
        if (A[i] < mx) {res += (mx - A[i]);}
        else {mx = max(mx, A[i]);}
    }
    cout << res << "\n";
}