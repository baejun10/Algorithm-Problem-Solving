#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector <int> vec;
    int n;
    cin >> n;
    for(int i = 0 ;i < n ; i++){
        int t;
        cin >> t; 
        vec.push_back(t);
    }
    make_heap(vec.begin(), vec.end());
    sort_heap(vec.begin(), vec.end());
    for(int i = 0 ; i < n; i++){
        cout << vec[i] << "\n";
    }


}