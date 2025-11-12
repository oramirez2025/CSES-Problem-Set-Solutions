#include <iostream>
#include <vector>
#include <utility> 


using namespace std;


// check if two queens can attack each other
bool queen_fight(int a, int b, int c, int d) {
    if (b == d) {
        return false;
    } else if (a == c) { 
        return false;
    } else if (abs(a - c) == abs(b - d)) {
        return false;
    }
    return true;
}

int solve(int queens, int i, int j, vector<pair<int,int>>& currConfig, vector<string> board) {
    if (queens == 0) {
        return 1;
    } else if (j == 8) {
        return solve(queens, i + 1, 0, currConfig, board);
    } else if (i == 8) {
        return 0; 
    } else {
        int res = 0;
        if (board[i][j] == '.') {
            bool noAttack = true;
            for (auto [a,b] : currConfig) {
                noAttack &= queen_fight(a,b,i,j);
            }
            if (noAttack) {
                currConfig.push_back({i,j});
                res += solve(queens - 1, i, j + 1, currConfig, board);
                currConfig.pop_back();
            }   
            res += solve(queens, i, j + 1, currConfig, board);
        } else {
            res += solve(queens, i, j + 1, currConfig, board);
        }
        return res; 
    }
}

int main() {
    vector<string> board;
    for (int i = 0; i < 8; ++i) {
        string currRow; cin >> currRow;
        board.push_back(currRow);
    }
    vector<pair<int,int>> currConfig;
    cout << solve(8, 0,0, currConfig, board);
}