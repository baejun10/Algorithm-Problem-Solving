#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, sum = 0;
    string n1;
    
    cin >> n;
    cin >> n1;
    for(int i = 0 ; i < n ; i++){
        sum += n1[i]-48;
    }
    cout << sum;

}