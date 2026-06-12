#include<iostream> 
#include<vector>
#include<string>

using ll = long long; 

int main() {
    int n; std::cin >> n;
    std::vector<std::vector<int>> grid(n, std::vector<int>(n, 0));
    std::vector<std::vector<ll>> dp(n, std::vector<ll>(n, 0));
    ll MOD = 1e9 + 7;

    
    for (int i = 0; i < n; ++i) {
        std::string line; std::cin >> line;
        for (int j = 0; j < n; ++j) {
            grid[i][j] = line[j];
        }
    }
    // BASE CASE
    dp[0][0] = grid[0][0] == '*' ? 0 : 1; 

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i == 0 && j == 0) || grid.at(i).at(j) == '*') continue;
            ll above = i - 1 > -1 ? dp.at(i - 1).at(j) : 0;
            ll left = j - 1 > -1 ? dp.at(i).at(j - 1) : 0;
            dp[i][j] = (above + left) % MOD;
        }
    }

    // IH: assume that dp[i][j] = c is the number of paths from (0,0) to (i,j) and note that 
    // if grid[i][j] == '*' then c = 0 o/w c > 0.

    // IS: 
    // supposed we want to count the number of paths to (i, j) 
    // so dp[i][j] = dp[i - 1][j] + dp[i][j - 1] 

    std::cout << dp.at(n - 1).at(n - 1) << '\n';

}