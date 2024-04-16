#include <iostream>

using namespace std;

int count_six(int n){
    int ex = 1;
    int digit = 0;
    int cnt_six = 0;
    while(ex <= n){
        ex *= 10;
        digit++;
    }
    ex/=10;
    int max = 0;
    for(int i = 0; i < digit; i++){
        int ans = n/ex;
        n -= ans*ex;
        ex /= 10;
        if(ans == 6){
            max++; // 최대 연속 6 개수
            if(max > cnt_six) cnt_six = max;
        }
        else max = 0;
    }
    return cnt_six;
}

int main()
{
    int n, i = 0;
    int ans = 666;
    cin >> n;
    // cout << count_six(n);
    while(ans){
        if(count_six(ans) >= 3) i++;
        if(i == n) break;
        ans++;
    }

    cout << ans;
}