#include <iostream>
bool parr[10000] = {0,};
bool is_prime(int p){
 
    if(p == 1) return 0; //1 소수 아님 제외

    for(int i = 2; i*i <= p; i++){ //에라토스테네스의 체 대신 소수의 제곱근보다 작은 모든값 검사
        if(p%i == 0){
            return 0;
        } 
    }
    return 1;
}
void initarr(){
    for(int i = 2; i <= 10000; i++){
        if(is_prime(i)) parr[i] = true;
        else parr[i] = false;
    }
}
int nextp(int n){
    for(int i = n+1; i <= 10000; i++){
        if(parr[i] == true) return i;
    }
    return 0;
}
using namespace std;

int main()
{
    initarr();
    int t;
    cin >> t;
    for(int i = 0 ; i < t; i++){
        int n;
        cin >> n;
        int p = 1;
        int min = 10000, mp = 0;
        while(true){
            int g = n;
            p = nextp(p);
            g -= p;
            if(p > n/2) break;
            if(parr[g] == true){
                if(min > (g-p)){
                    min = g - p;
                    mp  = p;
                }
            }
            if(g <= 0) printf("D.N.E.\n");
        }
        printf("%d %d\n", mp, n-mp);

    }
}