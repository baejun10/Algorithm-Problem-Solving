#include <iostream>
#include <string>
using namespace std;

int main()
{
    int d;
    int n, count = 0;
    cin >> n;
    // n의 자릿수 추출 string 이용
    for(int k = 1 ; k <= n ; k++){
        string hn = to_string(k);
        d= hn[0] - hn[1];
        // 어차피 아스키 코드 숫자도 순서대로 커지기 때문에 정수형변환 안해도 됨
        count++;
        for(int i = 1 ; i < hn.length()-1 ; i++){
            if(d != hn[i] - hn[i+1]){
                count--;
                break;
            }
            //한수아님
        }
    }
    cout << count;
    
}