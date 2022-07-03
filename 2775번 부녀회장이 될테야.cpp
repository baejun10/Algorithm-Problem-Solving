#include <iostream>

using namespace std;

int sol(int k, int n){
    int room[20][20] = {};
    for(int i = 1 ;i <= n; i++){
            room[0][i] = i;
    }
    for(int i = 1 ; i <= k ; i++){ //층
        for(int j = 1 ; j <= n ; j++){
            for(int s = 1; s <= j ; s++){
                room[i][j] += room[i-1][s];
            }
        }
    }
    return room[k][n];
}
int main()
{
    int t, k, n;
    cin >> t;

    for(int i = 0 ; i < t; i++){
        cin >> k >> n;
        
        cout << sol(k, n)<< endl;
    }
}