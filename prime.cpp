#include <iostream>
bool parr[10000] = {0,};
using namespace std;
bool is_prime(int);
void initarr(){
    for(int i = 2; i <= 10000; i++){
        if(is_prime(i)) parr[i] = true;
        else parr[i] = false;
    }
}


int main()
{
    initarr();
    for(int i = 1; i <= 10; i++){
        printf("%d ", parr[i]);
        if(parr[i] == true){
            
        }
    }

}
bool is_prime(int p){
 
    if(p == 1) return 0; //1 소수 아님 제외

    for(int i = 2; i*i <= p; i++){ //에라토스테네스의 체 대신 소수의 제곱근보다 작은 모든값 검사
        if(p%i == 0){
            return 0;
        } 
    }
    return 1;
}