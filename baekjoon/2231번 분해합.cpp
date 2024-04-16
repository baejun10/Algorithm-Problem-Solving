#include <iostream>

using namespace std;

int ds(int n){
    int tn = n;
    int ex = 10, digit, ds, digitSum = 0,tt = 0;
    for(digit = 1; n/ex >= 1; digit++, ex*=10); // digit 자릿수 구하기
    ex/=10;
    for(int i = 0 ; i < digit; i++, ex/=10){
        tt = n/ex;
        digitSum += tt;
        n -= tt*ex;
    }
    ds = tn + digitSum;
    return ds;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i < n ; i++){
        if(ds(i) == n){
            cout << i;
            return 0;
        }
    }
    cout << 0;

}