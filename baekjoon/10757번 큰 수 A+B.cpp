#include <iostream>
#include <string>
using namespace std;
int atoi(char in){
    int ans = in - '0';
    return ans;
}
int main()
{
    string a, b;
    //string ans = "";
    char ans[10001] = {0, };
    cin >> a >> b;
    int up = 0, tsum = 0, ex = 1;
    int len;
    if(a.size()>=b.size()){
        len = a.size(); //인덱스 0부터 이므로
        int r = len - b.size();
        for(int i = 0; i < r; i++){
            b.insert(0,"0");
        }
    }
    else{
        len = b.size();
        int r = len - a.size();
        for(int i = 0; i < r; i++){
            a.insert(0,"0");
        }
    }// 문자열 길이 맞춤

    for(int i = len - 1; i >= 0 ; i--){   
        tsum = atoi(a[i])+atoi(b[i]) + up;
            up = tsum/10;
            tsum -= up*10;
            ans[i] = tsum + '0'; // 문자열 숫자로 변환
    }

    if(up) printf("%d",up); // 마지막 up 있을 경우 출력
    printf("%s", ans);
    //
}