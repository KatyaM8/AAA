#include <iostream>
#include <vector>
int kolvo_dvoek(int a) {
    int k2 = 0;
    while (a > 0) {
        if (0 == a%2) {
            k2 += 1;
        }
        a = a / 2;
    }
    return k2;
}
int stepen(int b) {
    int fl = 0;
    while (b > 0) {
        if (0 == (b % 2)) {
            fl = 0;
        }
        else {
            fl = 1;
        }
        b = b / 2;
    }
    return fl;
}
int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int> arr(n);
    int s = 1;
    for (int i = 0; i < n; ++i) {
        std::cin>>arr[i];
    }
    for (int i = 0; i < n; ++i) {
        s = s * arr[i];
    }
    int kolvo2 = kolvo_dvoek(s);
    int kolvooper = 0;
    if (kolvo2 == n) {
        std::cout<<0;
    }
    else {
        for (int i = n - 1; i >= 0; i = i - 1) {   
            if (0 == stepen(i+1)) {
                if (kolvo_dvoek(s * i) == n) {
                    kolvooper += 1;
                    std::cout<<kolvooper;
                    break;
                }
                else {
                    s = s * i;
                    kolvooper += 1;
                }
            }
        }
    }
    std::cout<<stepen(8);
}
