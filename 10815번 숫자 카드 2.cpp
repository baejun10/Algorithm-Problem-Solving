#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n;
    unordered_map <int, int> mp; 

    for(int i=0; i<n; i++) {
        int num;
        cin >> num;
        if(mp.find(num) == mp.end()) {
            mp.insert({num, 1});
        } else {
            mp[num]++;
        }
        
    }

    cin >> m;
    for(int i=0; i<m; i++) {
        int num;
        cin >> num;
        cout << mp[num] << " ";
    }

    
}