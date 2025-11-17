#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;



int main() {
    int n,m; cin >> n >> m;
    vector<vector<int>> board;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        vector<int> curr(m);
        for (int j = 0; j < m; ++j) {
            char c = s[j];
            switch (c) {
                case 'A':
                    curr[j] = 0; break;
                case 'B':
                    curr[j] = 1; break;
                case 'C':
                    curr[j] = 2; break;
                case 'D':
                    curr[j] = 3; break;
            }
        }
        board.push_back(curr);
    }
    board[0][0] = (board[0][0] + 1) % 4;
    for (int i = 1; i < n; ++i) {
        unordered_set<int> choices {0,1,2,3};
        choices.erase(board[i - 1][0]);
        choices.erase(board[i][0]);
        if (choices.empty()) {
            cout << "IMPOSSIBLE";
            return 0;
        } 
        board[i][0] = *(choices.begin());
    }
    for (int j = 1; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            unordered_set<int> choices {0,1,2,3};
            choices.erase(board[i][j]);
            if (i - 1 > -1) choices.erase(board[i-1][j]);
            if (j - 1 > -1) choices.erase(board[i][j-1]);
            if (choices.empty()) {
                cout << "IMPOSSIBLE";
                return 0;
            } 
            board[i][j] = *(choices.begin());
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int c = board[i][j];
            switch (c) {
                case 0:
                    cout << 'A'; break;
                case 1:
                    cout << 'B'; break;
                case 2:
                    cout << 'C'; break;
                case 3:
                    cout << 'D'; break;
            }
        }
        cout << '\n';
    }
}