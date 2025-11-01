#include <iostream>
#include <set>
#include <unordered_map>
#include <limits>
using namespace std;
typedef long long ll;
/*
   - for each new person, we see that they either go on the end or in between two people
        - if they go on the end, they impact ONLY the last person
        - if they go in between, they impact on the people on the ends
   - for this reason, we need to binary search to see where the persons on the number line
   - then, we can compute their change to our running sum d
   - in the end, for each iteration we do O(log n) work
   - we have n iterations, so in total we've done O(n log n) work!



   We need to use a ordered_set or just a set to get that O(log n) insertion
*/


int main() {
    int N; cin >> N;
    set<ll> line = {0}; 
    unordered_map<ll, ll> nearest;
    ll res {0};
    ll firstPerson; cin >> firstPerson;
    nearest[0] = firstPerson;
    nearest[firstPerson] = firstPerson;
    res += (2 * firstPerson);
    line.insert(firstPerson);
    N--;
    cout << res << '\n';
    while (N--) {
        ll person; cin >> person;

        // find where the person belongs on the line
        auto it = line.lower_bound(person);

        // find the left and right neighbors (if they exist)
        bool hasLeft = false, hasRight = false;
        ll left,right;
        if (it != line.begin()) {left = *prev(it); hasLeft = true;}
        if (it != line.end()) {right = *it; hasRight = true;}

        // find who's the closest to the person inserted into the line
        ll closest = LLONG_MAX;
        if (hasLeft) closest = person - left; 
        if (hasRight) closest = min(closest, right - person); 

        // if the left neighbor does exist, then adjust his contribution
        if (hasLeft) {
            res -= nearest[left];
            nearest[left] = min(nearest[left], person - left);
            res += nearest[left];
        }
        // same for the right neighbor
        if (hasRight) {
            res -= nearest[right];
            nearest[right] = min(nearest[right], right - person);
            res += nearest[right];
        }

        line.insert(person);
        nearest[person] = closest;
        res += closest;
        cout << res << '\n';
    }
}