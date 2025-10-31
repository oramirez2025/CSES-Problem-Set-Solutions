#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <string>


int main() {
    std::string S; std::cin >> S;
    int n = S.size();
    std::map<char,int> counter;
    for (auto c: S) {
        counter[c]++;
    }
    std::vector<std::pair<char,int>> evens;
    std::vector<std::pair<char,int>> odds;
    for (auto &[k,v] : counter) {
        if (v % 2 == 0) {
            evens.push_back(std::pair(k,v));
        } else {
            odds.push_back(std::pair(k,v));
        }
    }
    if ((n % 2 == 0 && odds.size() > 0) || (n % 2 == 1 && odds.size() > 1)) {
        std::cout << "NO SOLUTION" << "\n";
        return 0;
    } else {
        // time to construct the palindrome! 
        std::string res = "";
        if (n % 2 == 0) {
            for (auto p : evens) {
                char c = p.first;
                int occur = p.second / 2;
                res = (std::string(occur,c) + res + std::string(occur,c));
            }
        } else {
            res = std::string(odds[0].second, odds[0].first);
            for (auto p : evens) {
                char c = p.first;
                int occur = p.second / 2;
                res = (std::string(occur,c) + res + std::string(occur,c));
            }
        }
        std::cout << res << "\n";
    }


}
