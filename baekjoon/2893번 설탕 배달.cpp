#include <iostream>

using namespace std;

int main()
{
    int n, ans;
    cin >> n;
    int fk = n/5;
    n -= fk*5;
    int tk = n/3;
    while(n%3){
        if(fk <= 0){
            cout << -1;
            return 0;
        }  
        n += 5;
        fk --;
        tk = n/3;   
    }
    cout << fk+tk;
    return 0;
}