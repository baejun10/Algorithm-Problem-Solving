#include <iostream>
#include <cstring>
using namespace std;

bool visit[5001] = {false, };
int memcnt[5001] = {0,};

// 분할정복 + 동적계획법 (겹치는 부분 저장)
int decrypt(char code[], int i, int len){
    if(code[i] == '0'){ //예외 시작이 0인경우 해독불가
        return 0;
    }

    int cnt = 0;
    
    if(i+1 >= len){
        return 1;
    } 

    int fDig = (code[0+i]-'0') * 10+(code[1+i]- '0');

    if(fDig > 26 || fDig < 10 ){ // 2자리 암호 아님 1자리만 암호
        if(visit[i+1]){
            cnt+= memcnt[i+1];
        }
        else{
            memcnt[i+1] = decrypt(code, i+1, len)%10000000;
            visit[i+1] = true;
            cnt += memcnt[i+1];
        }
    }
    else if(fDig == 20 || fDig == 10){ // 2자리만 가능++ 반례 1010 0으로 끝나는 2자리수 주의
        if(visit[i+2]){
            cnt+= memcnt[i+2];
        }
        else{
            memcnt[i+2] = decrypt(code, i+2, len)%10000000;
            visit[i+2] = true;
            cnt += memcnt[i+2];                
        }
    }
    else{ // 1자리, 2자리 암호 가능
        if(visit[i+1]){
            cnt+= memcnt[i+1];
        }
        else{
        memcnt[i+1] = decrypt(code, i+1, len)%10000000;
        visit[i+1] = true;
        cnt += memcnt[i+1];           
        }

        if(visit[i+2]){
            cnt+= memcnt[i+2];
        }
        else{
            memcnt[i+2] = decrypt(code, i+2, len)%10000000;
            visit[i+2] = true;
            cnt += memcnt[i+2];                
        }

    }
    return cnt;
}

int main()
{
    char code[5001] = {};
    cin >> code;

    cout << decrypt(code, 0, strlen(code));
}