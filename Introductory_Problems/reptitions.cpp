#include <iostream> 
#include <map> 
#include <string> 

using namespace std;

int main() {
    map<char, int> longest;
    string s; cin >> s;
    char currentLetter = '\0';
    int currentCount = 0;
    for (char c : s) {
        if (currentLetter == '\0') {
            currentLetter = c;
            currentCount++;
            longest[currentLetter] = max(currentCount, longest[currentLetter]);
        } else {
            if (currentLetter != c) {
                currentLetter = c;
                currentCount = 1;
            } else {
                currentCount++;
                longest[currentLetter] = max(currentCount, longest[currentLetter]);
            }
        }
    }
    int bestCount = 0;
    for (auto &[k,v] : longest) {
        if (v > bestCount) {
            bestCount = v;
        }
    }
    cout << bestCount << endl;
}
