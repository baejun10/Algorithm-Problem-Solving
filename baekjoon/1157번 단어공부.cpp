#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int main()
{
    int a[150] ={};
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(islower(s[i])){
            s[i] = toupper(s[i]);
        }
        a[s[i]]++;
    }
    // for(int i  = 'A' ; i <= 'Z' ; i++){
    //     printf("%d", a[i]);
    // }
    int max = 0;
    char ans;
    for(int i = 'A'; i <= 'Z' ; i++){

        if(a[i] > max){
            max = a[i];
            ans = i;
        }

        else if(a[i] == max && a[i] != 0){
            ans = '?';
        }
    }
    printf("%c", ans);

}