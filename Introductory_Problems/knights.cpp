#include <iostream>
#include <limits>
#include <vector>
#include <queue> 
#include <utility>

using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> board;
    for (int i = 0; i < n; ++i) {
        vector<int> curr;
        for (int j = 0; j < n; ++j) {
            curr.push_back(numeric_limits<int>::max());
        }
        board.push_back(curr);
    }
    vector<pair<int,int>> directions = {{-2,1},{-2,-1},{-1,2},{-1,-2},{1,2},{1,-2},{2,-1},{2,1}};
    int tot = (n * n);
    queue<pair<int,int>> q;
    q.push({0,0});
    int curr = 0;
    while (tot) {

        int k = q.size();
        for (int i = 0; i < k; ++i) {
            auto [x,y] = q.front();
            if (curr < board[x][y]) {
                board[x][y] = curr;
                tot -= 1;
                for (auto [dx,dy] : directions) {
                    int nx = x + dx, ny = y + dy;
                    if (-1 < nx && nx < n && -1 < ny && ny < n) {
                        q.push({nx,ny});
                    }
                }
            }
            q.pop();
        }
        curr++;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
}