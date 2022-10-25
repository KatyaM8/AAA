#include <iostream>
int main() {
    int n =0;
    std::cin>>n;
    int k1 = 0;
    while (n > 0) {
        if (1 == n % 2) {
            k1 += 1;
        }
        n = n / 2;
    }
    std::cout<<k1;
}
