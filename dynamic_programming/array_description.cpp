#include<iostream>
#include<vector>
#include<numeric>

/*
Input:

3 5
2 0 2
Output:

3

*/

// void print_vector(const std::vector<int>& v) {
//     for (auto& x : v) {
//         std::cout << x << " ";
//     }
// }


/*
    NOTES: 
        - When dealing with large sums, it's a good idea to use long long to hold those large values
        - std::acumulate(v.begin(), v.end(), initial value) from <numeric> 

*/

int main() {
    int n, m; std::cin >> n >> m;
    long long MOD = 1e9 + 7; 
    std::vector<int> X(n, 0);
    std::vector<std::vector<long long>> dp(n, std::vector<long long>(m + 2, 0));
    for (auto& x : X) {
        std::cin >> x;
    }
    // i \in {0,1,2,...,n}
    // v \in {1,2,3...,m}
    // BASE CASE: one element vector
    for (int v = 1; v <= m; ++v) {
        dp[0][v] = (v == X[0] || X[0] == 0);
    }
    for (int i = 1; i < n; ++i) {
        // we choose the value for X[i]
        if (X[i] == 0) {
            for (int v = 1; v <= m; ++v) {
                dp[i][v] += ((dp[i - 1][v - 1] + dp[i - 1][v] + dp[i - 1][v + 1]) % MOD);
            }
        } else {
            dp[i][X[i]] += ((dp[i - 1][X[i] - 1] + dp[i - 1][X[i]] + dp[i - 1][X[i] + 1]) % MOD);
        }
    }
    // for (auto& v : dp) {
    //     print_vector(v);
    //     std::cout << '\n';
    // }
    std::cout << (std::accumulate(dp.at(n - 1).begin(), dp.at(n - 1).end(), 0LL) % MOD) << '\n';

}