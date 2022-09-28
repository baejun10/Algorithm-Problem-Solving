#include <iostream>
#include <cstring>
using namespace std;

int cnt;
int recursion(const char *s, int l, int r){
    cnt++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    for(int i =0; i< t; i++){
        char in[1001];
        cnt = 0;
        cin >> in;
        cout << isPalindrome(in) << " ";
        cout << cnt << "\n";

    }
}