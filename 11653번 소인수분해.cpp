#include <iostream>

using namespace std;

void is_prime(int *p){
    bool is_p = 1;
    
    if(*p == 1) {
        //cout << 1; //1은 인수로 출력 안함
        return ;
    } 

    for(int i = 2; i <= *p; i++){
        if(*p%i == 0){
            *p /= i;
            cout << i << endl;
            is_prime(p);
            return ;
        } 
    }

}

int main()
{
    int n;
    cin >> n;
    is_prime(&n);
}