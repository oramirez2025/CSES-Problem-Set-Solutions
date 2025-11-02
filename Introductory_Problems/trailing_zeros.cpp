#include <iostream>
#include <algorithm>

typedef unsigned long long ull;



int computeTwos(int curr) {
    int res = 0;
    while (curr % 2 == 0) {
        res++;
        curr /= 2;
    }
    return res;
}
int computeFives(int curr) {
    int res = 0;
    while (curr % 5 == 0) {
        res++;
        curr /= 5;
    }
    return res;
}

int main() {
    ull n; std::cin >> n;
    int numberOfTwos = 0;
    int numberOfFives = 0;
    for (ull k = 2; k <= n; k += 2) {
        numberOfTwos += computeTwos(k);
    }
    for (ull k = 5; k <= n; k += 5) {
        numberOfFives += computeFives(k);
    }
    std::cout << std::min(numberOfTwos,numberOfFives) << "\n";

}



// 