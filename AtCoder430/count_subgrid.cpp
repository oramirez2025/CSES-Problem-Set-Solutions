#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<string> board;
    set<string> seen;
    for (int i = 0; i < N; ++i) {
        string curr; cin >> curr;
        board.push_back(curr);
    }
    for (int row = 0; row < N - M + 1; ++row) {
        for (int col = 0; col < N - M + 1; ++col) {
            string curr = "";
            for (int i = 0; i < M; ++i) {
                for (int j = 0; j < M; ++j) {
                    curr += board[row + i][col + j];
                }
            }
            seen.insert(curr);
        }
    }
    cout << seen.size() << '\n';
}