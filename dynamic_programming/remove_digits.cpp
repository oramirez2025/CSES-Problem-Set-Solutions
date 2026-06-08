#include<iostream>
#include<vector>
#include<string> 
#include<algorithm>


// overall, the time complexity is O(n * d), where d is the max number of digits, which can be represented in log n bits so O(n * log n) is the time complexity
int main() {   
    int n; std::cin >> n;
    int INF = n + 1;
    std::vector<int> dp(n + 1, INF);
    dp[0] = 0;
    // We can optimize this to use modular arithmetic to find the digits rather than converting to a string 
    for (int i = 1; i <= n; ++i) {
        std::string s = std::to_string(i);
        for (char c : s) {
            int digit = c - '0'; // when doing the subtraction, it uses ascii values so to find the digit we subtract it from '0' (i.e., starting ascii val)
            if (digit == 0) continue;
            dp[i] = std::min(
                dp[i],
                1 + dp.at(i - digit)
            );
        }
    }
    std::cout << dp.at(n) << '\n';

}