#include <iostream>

using namespace std;

bool is_self[100000] = {};

int pow(int n, int s){
    if(s == 0) return 1;

    int ans = 1;
    for(int i = 0 ; i < s ; i++){
        ans *= n;
    }
    return ans;
}

void ch_self(int n){
    int s_num = n ; // self num 구하는 공식중 n 
    int i = 1;
    s_num += n%10;// 1의 자릿수 계산은 따로 해야함


    while(pow(10,i) <= n){ //10의 i 제곱 10*i자릿수 구라기
        //cout << "+ " << n/pow(10,i) - n/pow(10,i+1)*10;
        s_num += n/pow(10,i) - n/pow(10,i+1)*10;
        i++; // 다음 자릿수
        //cout << s_num << endl;
    }

    is_self[s_num] = 1; //self_number가 아님
    //cout << s_num << " is not self numeber!";
}

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    for(int i = 1 ; i <= 10000 ; i++ ){
        ch_self(i);
    }
    for(int i = 1 ; i <= 10000 ; i++ ){
        if(is_self[i] == 0) cout << i << "\n";
    }
    
}