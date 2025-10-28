#include <iostream> 
using namespace std;

int main() {
    string s; cin >> s;
    int n = s.size();
    int curr,res = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1]) {
            curr = 0;
        }
        curr++;
        res = max(res, curr);
    }
    cout << res << endl;
}
