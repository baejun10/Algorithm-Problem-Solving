#include <iostream>
#include <string>

using namespace std;

void getnum(string in, int ans[]){
    int base = 'A'-1; // 숫자로 변환 기준 A부터 1, B = 2, ...
    for(int i = 0 ; i < in.size() ; i++){
        if(in[i] == 'Z' || in[i] =='Y') //Z, Y는 예외
            ans[i] = 9;
        else if(in[i] == 'S')
            ans[i] = 7;
        else if(in[i] == 'V')
            ans[i] = 8;
        else if((in[i]-base)%3)
            ans[i] = (in[i]-base)/3+2;
        else
            ans[i] = (in[i]-base)/3+1;
    }
}

int get_time(int num[]){
    int time = 0;
    for(int i = 0 ; num[i] != 0 ; i++){
        time += num[i]+1;
    }
    return time;
}

int main()
{
    int num[16] = {};
    string in;
    cin >> in;
    getnum(in, num);
    // for(int i  = 0 ; num[i] != 0; i++){
    //     cout << num[i];
    // }
    cout << get_time(num);
}