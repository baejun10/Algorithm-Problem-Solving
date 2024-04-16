#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, k;
    int grd[1001] = {};
    cin >> n >> k;
    
    for(int i = 0 ;i < n ;i++){
        cin >> grd[i];
    }
    sort(grd, grd+n);
    cout << grd[n-k];
}