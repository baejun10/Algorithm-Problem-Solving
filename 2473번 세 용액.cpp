#include <algorithm>
#include <iostream>
#include <limits.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    long long int sp[6000] = {};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> sp[i];
    }
    sort(sp, sp + n);
    long long int min = 3000000005;
    long long int min_element[3];
    for (int i = 0; i < n; i++) {
        int left = 0, right = n - 1;
        while (left < right) {
            if (left == i) {
                left++;
                continue;
            }
            if (right == i) {
                right--;
                continue;
            }
            long long int sum = sp[i] + sp[left] + sp[right];
            if (std::abs(sum) < min) {
                min = std::abs(sum);
                min_element[0] = sp[i];
                min_element[1] = sp[left];
                min_element[2] = sp[right];
            }
            if (sum < 0) {
                left++;

            } else if (sum > 0) {
                right--;

            } else {
                break;
            }
        }

    }
    sort(min_element, min_element + 3);
    for (auto el : min_element) {
        cout << el << " ";
    }
}