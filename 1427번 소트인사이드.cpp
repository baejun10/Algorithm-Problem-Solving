#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {
    int n, digit = 1, dn = 1;
    int num[20] = {};

    cin >> n;
    while (digit < n) {
        digit *= 10;
        dn++;
    }
    if (digit > n) {
        digit /= 10;
        dn--;
    }

    for (int i = 0; i < dn; i++) {
        num[i] = n / digit;
        n -= num[i] * digit;
        digit /= 10;
    }
    sort(num, num + dn, greater<int>());
    for (int i = 0; i < dn; i++) {
        cout << num[i];
    }
}