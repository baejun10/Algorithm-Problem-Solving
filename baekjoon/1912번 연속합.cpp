#include <iostream>
using namespace std;

int main() {
    int n;
    int dp;
    int ans = -1001;
    cin >> n;
    cin >> dp;
    ans = dp;
    for (int i = 1; i < n; i++) {
        int num;
        cin >> num;

        if(dp > 0) {
            dp = max(dp + num, num);
        } else {
            dp = max(num, dp);
        }
        ans = max(ans, dp);
        // cout << " dp: " << dp << '\n';
    }   
    cout << ans << '\n';
    return 0;
}