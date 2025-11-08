#include <iostream>

typedef long long ll;
/*
// so we have to find the digit at the kth index in this infinite string
// Well, we know that the single digits live in the interval [0,8]
// then, the double digits live in the interval [9, 188]
// the triple digits live in the interval [189, 2618]
//                                         100  999
// the quadruple digits live in the interval [2619, 31778]
//                                            1000, 9999
// okay, let's try to generalize this??? 
// suppose we're looking at the dth digits so we're thinking about the numbers 
// in the [10^{d - 1}, 9^{d}] so 10..0 - 9...9
// cool, so I found the function for the starting index: 
// f(1) = 9, f(d) = f(d - 1) + (d * 10) * (9^{d - 1}), where d >= 2
// to find the right endpoint we do 
// (f(d) + ((d + 1) * 10) * (9^{d})) - 1
// come back to this later lol 
*/

void solve(ll k) {
    if (0 <= k && k <= 8) {
        NULL;
    } else {
        ll d = 2;
        ll l = 9, r = 188;
        while (!(l <= k && k <= r)) {
            d++;
            l += (d * 10) * (pow(9, d - 1));
            r = (l + ((d + 1) * 10) * (pow(9, d))) - 1;
        }
        // cool, now we know l <= k <= r but this is too big to determine??? we should go into the sub intervals
        ll rr = l + (d * 10);
        ll number = pow(10, d - 1);
        while (!(l <= k && k <= rr)) {
            number += 10;
            l = rr;
            rr = l + (d * 10);
        }
        rr--;
        std::cout << "l = " << l << " rr = " << rr << " d = " << d << " number = " << number << '\n';
        // rrr = 
        for (int i = number; i < number + 10; ++i) {

        }
    }
}


int main() {
    int queries; std::cin >> queries;
    while (queries--) {
        ll k; std::cin >> k;
        solve(k);
    }
}