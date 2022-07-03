#include <iostream>

using namespace std;

bool is_prime(int p){
    bool is_p = 1;
    
    if(p == 1) return 0; //1 소수 아님 제외

    for(int i = 2; i < p; i++){
        if(p%i == 0){
            is_p = 0;
            return is_p;
        } 
    }
    return is_p;
}
int main()
{
    int m, n, min = 0, sum = 0;
    cin >> m >> n;
    for(int i = m ; i <= n; i++ ){
        if(is_prime(i)){
            if(min == 0) min = i;
            else if(min > i) min = i;
            sum += i;
        }
    }
    if(sum == 0 && min == 0){
        cout << -1;
        return 0;
    }

    cout << sum << endl;
    cout << min << endl;
    return 0;
}