#include <iostream> 
#include <vector>
typedef unsigned long long ull;
using namespace std;


ull solve(ull x) {
    if (x % 2 == 0) {
        return (x / 2);
    } else {
        return ((3 * x) + 1);
    }
}

int main() {
    ull n; cin >> n;
    vector<ull> result;
    result.push_back(n);
    while (n > 1) {
        ull tmp = solve(n);
        result.push_back(tmp);
        n = tmp;
    }
    for (auto s : result) {
        cout << s << " ";
    }
}