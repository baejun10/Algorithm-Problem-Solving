#include <iostream>

using namespace std;

bool is_prime(int p){
 
    if(p == 1) return 0; //1 소수 아님 제외

    for(int i = 2; i*i <= p; i++){ //에라토스테네스의 체 대신 소수의 제곱근보다 작은 모든값 검사
        if(p%i == 0){
            return 0;
        } 
    }
    return 1;
}

int main()
{
    while(1){
        int n, cnt = 0;
        cin >> n;
        if(n == 0) break;
        for(int i = n+1; i <= 2*n; i++){
            if(is_prime(i)) cnt++;
            //cout << i << endl;
        }
        cout << cnt << endl;
    }
}