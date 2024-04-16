#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    int ans = 0;
    cin >> n >> m;
    unordered_set <string> s; 

    for(int i=0; i<n; i++) {
        string name;
        cin >> name;
        s.insert(name);
        
    }
    for(int i=0; i<m; i++) {
        string name;
        cin >> name;
        if(s.find(name) != s.end()) {
            ans++;
        }
    }
    cout << ans;

    
}