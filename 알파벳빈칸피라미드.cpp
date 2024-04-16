#include <iostream>
using namespace std;

int main()
{
    int n = 7;
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n; j++){
            if(j < n-i){
                if(i == 0 && j == n-1) continue; //맨 윗줄 맨 오른쪽 알파벳 제거
                char p = 'A'+j;
                cout << p;
            }
            else{
                if(j==n-1) continue; //맨 오른쪽 공백 제거
                cout << ' ';
            }
        }
        for(int j = n; j >= 0; j--){
            if(j < n-i){
                char p = 'A'+j;
                cout << p ;//'A'+n부터 시작해서 'A'까지
            }
            else{
                if(j==n) continue; //맨 왼쪽 공백 제거
                cout << ' ';
            }
        }
        cout << endl;
    }
}