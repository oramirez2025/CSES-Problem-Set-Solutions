#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>

int main() {
    int n, x; std::cin >> n >> x;
    std::vector<int> prices(n);
    for (auto& x : prices) {
        std::cin >> x;
    }
    std::vector<int> pages(n);
    for (auto& x : pages) {
        std::cin >> x;
    }
    // dp[i][c] = max number of pages bought with budget c and looking at the first i books
    std::vector<std::vector<int>> dp(n, std::vector<int>(x + 1, 0));
    

    // base case: i = 0 (i.e., looking at no books) so the max number of pages is 0

    for (int c = prices[0]; c <= x; ++c) {
        dp[0][c] = pages[0];
    }

    for (int i = 1; i < n; ++i) {
        for (int c = 0; c <= x; ++c) {
            dp[i][c] = dp[i - 1][c];
            if (c >= prices[i]) {
                dp[i][c] = std::max(
                    dp[i][c],
                    pages[i] + dp[i - 1][c - prices[i]] // choose to purchase the book
                );
            }
        }
    }
    std::cout << dp.at(n - 1).at(x) << '\n';

}