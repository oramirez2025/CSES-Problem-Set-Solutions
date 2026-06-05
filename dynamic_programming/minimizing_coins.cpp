#include<iostream>
#include<vector>


int main() {
    int n, x; std::cin >> n >> x;
    std::vector<int> C(n);
    const int INF = 1e9;
    // dp[i] = min number of coins to sum up to i

    // then, the transition is
    // to use coin c_j, 
    // dp[i] = min(
    //              dp[i],
    //              1 + dp[i - c_j]
    //         )
    std::vector<int> dp(x + 1, INF); 


    for (auto& x : C) {
        std::cin >> x;
    }
    // two loops 
    // one for the coins
    // the other for the possible sum



    // base case: dp[0] = 0 because it requires 0 coins to make sum 0
    dp[0] = 0;

    // pick some sum x and some coin c_j
    // then, the transition is 
    // sum = 0, 1, 2, ..., x + 1
    // i = 0, 1, ..., n 
    for (int i = 0; i < n; ++i) {
        int coin = C[i];
        for (long sum = coin; sum <= x; ++sum) {
            dp[sum] = std::min(
                dp[sum], 
                1 + dp[sum - coin]
            );
        }
    }
    std::cout << (dp[x] != INF ? dp[x] : -1) << '\n';
}