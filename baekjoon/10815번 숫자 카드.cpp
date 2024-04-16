#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n;
    unordered_set <int> s; 

    for(int i=0; i<n; i++) {
        int num;
        cin >> num;
        s.insert(num);
        
    }

    cin >> m;
    for(int i=0; i<m; i++) {
        int num;
        cin >> num;
        if(s.find(num) != s.end()) {
            cout << 1 << " ";
        } else {
            cout << 0 << " ";
        }
    }

    
}