#include <iostream>

using namespace std;

int main()
{
    int n[100], max = 0, mi = 0;
    for(int i = 1; i <= 9; i++){
        cin >> n[i];
        if(max < n[i]){
            mi = i;
            max = n[i];
        }
    }
    cout << max << endl;
    cout << mi << endl;
}