#include <iostream>
#include <algorithm>

typedef unsigned long long ull;

void solve() {
    ull row,col; std::cin >> row >> col;
    ull mx = std::max(row,col);
    // if it's even, start from the row
    if (mx % 2 == 0) {
        ull val = (mx*mx);
        ull currRow = mx, currCol = 1;
        while (currCol < col) {
            currCol++;
            val--;
        }
        while (row < currRow) {
            currRow--;
            val--;
        }
        std::cout << val << "\n";
    // if it's odd, start from the col
    } else {
        ull val = (mx * mx);
        ull currRow = 1, currCol = mx;
        while (currRow < row) {
            currRow++;
            val--;
        }
        while (currCol > col) {
            currCol--;
            val--;
        }
        std::cout << val << "\n";
    }


}

int main() {
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
}