#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<bool> seen(n + 1, false);
    for (int i = 0; i < n - 1; ++i) {
        int curr; cin >> curr;
        seen[curr] = true;
    }

    for (int i = 1; i < n + 1; ++i) {
        if (!seen[i]) {
            cout << i << endl;
            break;
        }
    }
}