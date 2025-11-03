#include <iostream> 
#include <vector>
#include <algorithm>



int main() {
    std::string s; std::cin >> s;
    std::vector<char> word;
    for (auto c : s) {
        word.push_back(c);
    }
    std::vector<std::string> allPerms; 
    // next_permutation only works when the vector is sorted!
    sort(word.begin(), word.end());
    do {
        std::string res = "";
        for (auto c : word) {
            res += c;
        }
        allPerms.push_back(res);
    } while (std::next_permutation(word.begin(), word.end()));
    sort(allPerms.begin(), allPerms.end());
    std::cout << allPerms.size() << '\n';
    for (auto s : allPerms) {
        std::cout << s << '\n';
    }

}