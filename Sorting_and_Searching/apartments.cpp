#include <iostream> 
#include <vector>
#include <algorithm>
int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> apts(n);
    std::vector<int> sizes(m);
    for (int i = 0; i < n; ++i) {
        std::cin >> apts[i];
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> sizes[i];
    }
    std::sort(apts.begin(), apts.end());
    std::sort(sizes.begin(), sizes.end());
    int l = 0;
    int r = 0;
    int res = 0;
    while (l < n && r < m) {
        int desiredSize = apts[l];
        int availableSize = sizes[r];
        if (availableSize < desiredSize - k) {
            // apartment too small
            r++;
        } else if (availableSize > desiredSize + k) {
            // apartment too big for this applicant
            l++;
        } else {
            // acceptable
            res++;
            l++;
            r++;
        }
    }
    std::cout << res << std::endl;
    
}