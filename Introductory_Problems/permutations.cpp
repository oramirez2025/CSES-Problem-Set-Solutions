#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> res;
    for (int i = n - 1; i >= 1; i -= 2) {
        res.push_back(i);
    }
    for (int i = n; i >= 1; i -= 2) {
        res.push_back(i);
    }

    if (n == 2) {
        cout << "NO SOLUTION" << "\n";
        return 0;
    }

    for (int i = 1; i < n - 1; ++i) {
        if (abs(res[i] - res[i - 1]) == 1 || abs(res[i + 1] - res[i]) == 1) {
            cout << "NO SOLUTION" << "\n";
            return 0;
        }
    }

    for (auto x : res) {
        cout << x << " ";
    }
    return 0;
}
