#include <iostream> 
#include <vector>
using namespace std;


// 1 2 3 4 5 
// 3 4 5 6 7

int main() {
    int t; cin >> t;
    while (t--) {
        int n,a,b; cin >> n >> a >> b;
        int ties = n - a - b;
        if (ties < 0) {
            cout << "NO\n";
            continue;
        } 
        n -= ties;
        if (n < 0) { 
            cout << "NO\n";
            continue;
        }
        
        
        if (n >= 1 && (a == n || b == n)) {
            cout << "NO" << '\n';
            continue;
        } else {
            cout << "YES" << '\n';
            for (int i = 1; i <= n; ++i) {
                cout << i << " ";
            }
            for (int i = n + 1; i <= n + ties; ++i) {
                cout << i << " ";
            }
            cout << '\n';
            for (int i = 1; i <= n; ++i) {
                int x = i + a;
                if (x > n) {
                    x -= n;
                }
                cout << x << " ";
            }
            for (int i = n + 1; i <= n + ties; ++i) {
                cout << i << " "; 
            }
            cout << '\n';
        }
    }
}