#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int rep;
        string s;
        cin >> rep;
        cin >> s;
        for(int j = 0 ; j < s.size() ; j++){
            for(int k = 0 ; k < rep ; k++){
                cout << s.at(j);
            }
        }
        cout << endl;

    }
}