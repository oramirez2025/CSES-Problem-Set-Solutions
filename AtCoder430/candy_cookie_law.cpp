#include <iostream>

using namespace std;

int main() {
    int A,B,C,D; cin >> A >> B >> C >> D;
    if (C >= A  && !(D >= B)) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
}