#include <iostream> 
#include <vector>
#include <set>

using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> A;
    for (int i = 0; i < n; ++i) {
        vector<int> B(n);
        A.push_back(B);
    }
    for (int k = 0; k < n; ++k) {
        A[0][k] = k;
        A[k][0] = k;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            set<int> seen; 
            for (int k = i - 1; k > -1; --k) {
                seen.insert(A[k][j]);
            }
            for (int k = j - 1; k > -1; --k) {
                seen.insert(A[i][k]);
            }
            int curr = 0;
            while (seen.find(curr) != seen.end()) {
                curr++;
            }
            A[i][j] = curr;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << A[i][j] << " ";
        }
        cout << '\n';
    }
}