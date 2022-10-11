#include <iostream>
#include <vector>

int main () {
    int n = 0;
    std::cin>>n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i ++) {
        std::cin>>a[i];
    }
    int k = 2;
    int mink = 1245944944;
    int fl = 0;
    for (int i = 0; i < n; i ++) {
        if (a[i] == 0) {
            for (int j = i + 1;j<n; j++) {
                if (a[j] == 0) {
                    k += 1;
                }
                else {
                   if (k < mink) {
                       mink = k;
                }
                }
            }
        }
        if (k == 2) {
            mink = 2;
        }
        else {
            mink = 0;
        }
    }
    std::cout<<mink;
}