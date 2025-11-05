#include <iostream>
#include <set>
#include <algorithm>

int main() {
    int n; std::cin >> n;
    std::set<int> seen;
    int res {0};
    for (int i = 0; i < n; ++i) {
        int curr; std::cin >> curr;
        if (seen.find(curr) == seen.end()) {
            res++;
            seen.insert(curr);
        }
    } 
    std::cout << res << '\n';
}