#include<iostream>
#include<vector>

int main() {
    long long MOD = 1e9 + 7;
    int n; std::cin >> n;
    // Right, so if we're trying to reach sum n using dice rolls that are from 1 - 6 
    // well, let dp[x] = number of ways to reach x then dp[x] = dp[x - 1] + dp[x - 2] + ... + dp[x - 6]
    // because if we know how many ways to get x - 6, for example, we would need to roll a 6 to reach x
    // and because we are trying to sum up to n, we have n + 1 values (including 0 as there's one way to do that)
    
    
    // we'd also have to do bottom up? 
    std::vector<int> dp(n + 1);
    dp[0] = 1; // base case: there's 1 way to roll 0 (not rolling at all) 

    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < 7; ++j) {
            if (i - j <= -1) {
                break;
            } else {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }
    std::cout << (dp[n]) << '\n';
}