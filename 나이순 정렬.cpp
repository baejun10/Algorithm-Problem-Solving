#include <iostream>
#include <map>

using namespace std;


int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    multimap <int, string> m;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        string name ={};
        int age = 0;
        
        cin >> age >> name;
        m.insert(make_pair(age, name));
    }
    for(auto iter:m){
        cout << iter.first << " " << iter.second << "\n";
    }
}