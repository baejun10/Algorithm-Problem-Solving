#include <iostream>

using namespace std;
int ans;
int fac(int n){ // 재귀함수
    if(n == 0) return 1;
    if(n == 1) return 1;
    return fac(n-1)*n;
}

int main()
{
    cin >> ans;
    cout << fac(ans);
}