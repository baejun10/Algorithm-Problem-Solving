#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a[150] ={};
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        a[s[i]]++;
    }
    
}