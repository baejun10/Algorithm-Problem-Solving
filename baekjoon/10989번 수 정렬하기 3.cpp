#include <iostream>
#include <vector>
using namespace std;

int count[10001] = {};
// 정렬할 수의 범위가 좁으면 카운팅 소트가 유용하다

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int t;
        cin >> t;
        count[t]++;
    }
    for(int i = 1 ; i <= 10000 ; i++){
        for(int k = 0 ; k < count[i]; k++){
            cout << i << " ";
        }
    }

    
}