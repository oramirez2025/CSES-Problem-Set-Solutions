#include <iostream> 
#include <vector>
#include <algorithm>



// Solution without next_permutation

void backtrack(std::vector<char>& word, int index, std::vector<std::string>& allPerms) {
    if (index == word.size()) {
        allPerms.push_back(std::string(word.begin(), word.end()));
        return;
    } else {
         for (int i = index; i < word.size(); ++i) {
            std::swap(word[index], word[i]);
            backtrack(word, index + 1, allPerms);
            std::swap(word[index],word[i]);
         }
    }
}



int main() {
    std::string s; std::cin >> s;
    std::vector<char> word(s.begin(),s.end());
    std::vector<std::string> allPerms;
    backtrack(word, 0, allPerms);
    std::sort(allPerms.begin(), allPerms.end());
    std::cout << allPerms.size() << '\n';
    for (auto& p : allPerms) {
        std::cout << p << '\n';
    }

}


// Solution using next_permutation

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