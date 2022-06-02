#include <iostream>
#include <string>

using namespace std;

int main()
{
    int blank = 0;
    string s;
    getline(cin, s);
    if(s.size() == 0 || s.size() == 1 && s[0] == ' '){
        cout << 0;
        return 0;
    }

    for(int i = 1; i < s.size()-1; i++){
        if(s[i] == ' ')
            blank++;
    }
    cout << blank+1;
    
}