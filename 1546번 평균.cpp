#include <iostream>

using namespace std;

int main()
{
    int n, max = 0;
    float tot = 0, sc[1000] = {};
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> sc[i];
        max = sc[i]>max ? sc[i]:max;

    }

    for(int j = 0; j < n ; j++){
        sc[j] = sc[j]/max*100;
        tot += sc[j];
    }
    cout << tot/n;

}