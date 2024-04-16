#include <iostream>
#include <algorithm>
using namespace std;


bool cmp(string a, string b){
    if(a.size() < b.size()) return true;
    else if (a.size() > b.size()) return false;
    int i = 0;
    while(a[i] != '\0'){
        if(a[i] < b[i]) return true;
        else if(a[i] > b[i]) return false;
        i++;
    }
    return false;
}
int main(int argc, char const *argv[]) {
    int n;
    string arr[20000];
    cin >> n;
    for(int i = 0 ;i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n, cmp);
    for(int i = 0 ;i < n-1; i++){
    if(arr[i] != arr[i+1])
    cout << arr[i] << endl;
    }
    cout << arr[n-1] << endl;

}