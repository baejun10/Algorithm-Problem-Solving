#include <iostream>

using namespace std;

int selCard(int card[], int n ,int m){
    int sum = 0, max_s = 0;
    for(int i = 0; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            for(int k = j+1; k < n ; k++){
                sum = card[i] + card[j] + card[k];
                if(sum > max_s && m >= sum) max_s = sum;
            }
        }
    }
    return max_s;
}

int main()
{
    int n, m, card[101], sum, min;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        cin >> card[i];
    }
    cout << selCard(card, n, m);
}