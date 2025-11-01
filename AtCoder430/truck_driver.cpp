#include <iostream>
#include <vector>
using namespace std;


/*
    Sliding window technique; however, we kinda want to split it into two windows!
    The first window is for the a's while the second is for the b's based on the 
    condition given by the problem. Note, we care more about the right endpoint of 
    the b's window because we can shave off b's window but shaving off the a's window
    is a bit more cumbersome because we need # of a's >= A. 
*/


int main() {
    int N, A, B; cin >> N >> A >> B;
    string S; cin >> S;
    vector<int> prefixA(N);
    vector<int> prefixB(N);
    prefixA[0] = static_cast<int>(S[0] == 'a');
    prefixB[0] = static_cast<int>(S[0] == 'b');
    for (int i = 1; i < N; ++i) {
        prefixA[i] = (prefixA[i - 1] + static_cast<int>(S[i] == 'a'));
        prefixB[i] = (prefixB[i - 1] + static_cast<int>(S[i] == 'b'));
    }
    long long res = 0;
    int rA = 0, rB = 0;
    for (int l = 0; l < N; ++l) {
        while (rA < N && prefixA[rA] - (l > 0 ? prefixA[l - 1] : 0) < A) rA++;
        while (rB < N && prefixB[rB] - (l > 0 ? prefixB[l - 1] : 0) < B) rB++;
        if (rA >= N) break;
        if (rA < rB) {
            res += (rB - rA);
        }
    }
    cout << res << '\n';
}