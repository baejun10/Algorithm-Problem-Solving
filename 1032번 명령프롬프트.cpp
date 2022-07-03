#include <iostream>
#include <string>
using namespace std;
bool dif[50] = {false, };
void strcmp(string a, string b){
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]) dif[i] = true;
    }
}
int main()
{
    string in[50] = { };
    int n;
    cin >> n;
    for(int i = 0; i < n ;i++){
        cin >> in[i];
    }
    for(int i = 1; i < n ;i++){
        strcmp(in[0], in[i]);
    }
    for(int i = 0; i < in[0].size(); i++){
        if(dif[i]== true) cout << '?';
        else cout << in[0].at(i);
    }

}