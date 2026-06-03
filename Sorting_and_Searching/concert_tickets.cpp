#include<iostream>
#include<set>

int main() {
    int n, m; std::cin >> n >> m;
    std::multiset<int> tickets;
    for (int i = 0; i < n; ++i) {
        int x; std::cin >> x;
        tickets.insert(x);
    }

    for (int i = 0; i < m; ++i) {
        int asking_price; std::cin >> asking_price;
        auto it = tickets.upper_bound(asking_price);

        if (it == tickets.begin()) {
            std::cout << -1 << '\n';
        } else {
            --it;
            std::cout << *it << '\n';
            tickets.erase(it);
        }
    }

}