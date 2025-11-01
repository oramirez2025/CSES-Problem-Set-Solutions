#include <iostream>
#include <vector>

/*
    For this one, it seems like you needed to notice the pattern that you can use
    the solution for (n - 1) to get n.

    For example, if n = 1: then it's 0,1
    Now, for n = 2, the solution will start will the n = 1 case but shifted so:
        - 00
        - 01
    To get the last two, we know it'll start with 1x (where x is either x \in {0,1})
    Thus, it'll look something like this: 
        - 00
        - 01
        - 1x
        - 1x
    The x's we can fill in using the solution for n - 1 (in our case n = 1) but backwards so
        - 00
        - 01
        - 11
        - 10
    I would suggest trying this with n = 3 (it's pretty cool to see lol)
*/ 


std::vector<std::string> solve(int n) {
    if (n == 1) {
        return std::vector<std::string> {"0","1"};
    } else {
        std::vector<std::string> prev = solve(n - 1);
        std::vector<std::string> result;
        // we need the n - 1 solution but shifted
        for (auto c : prev) {
            result.push_back("0" + c);
        }
        // we work backwards from the n - 1 solution but prepend 1 to get the other 2^{n - 1} binary strings
        for (int i = prev.size() - 1; i > -1; --i) {
            result.push_back("1" + prev[i]);
        }
        return result;

    }
}


int main() {
    int n; std::cin >> n;
    std::vector<std::string> solved = solve(n);
    for (auto s : solved) {
        std::cout << s << '\n';
    }
}