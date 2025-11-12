#include <iostream>
#include <vector>
#include <utility>

using namespace std;


// the solve function works similar to how an inductive proof would work
// base case is 0, which results in 0 
// IH is just that we can do it for n - 1 and now we want to do it for n
// For the n - 1 smaller disks, we move that to the second stack, which we know is possible by induction
// Then, we move the largest disk to the third stack
// Lastly, we move the n - 1 smaller disks to the third stack using the now empty first stack as an intermediary stack
void solve(int n, int src, int dest, int aux, vector<pair<int,int>>& moves) {
    if (n == 0) {
        return;
    }
    solve(n - 1, src, aux, dest, moves); // solve the n - 1 smallest disks to the second 
    moves.push_back({src, dest}); // move the largest disk to the third stack
    solve(n - 1, aux, dest, src, moves); // lastly, move the n - 1 smallest disks to the third stack using the first stack 


}


int main() {
    int n; cin >> n;
    vector<pair<int,int>> moves;
    if (n == 1) {
        moves.push_back({1,3});
    } else {
        solve(n, 1, 3, 2, moves);
    }
    cout << moves.size() << '\n';
    for (auto [a,b] : moves) {
        cout << a << " " << b << '\n';
    }
}
