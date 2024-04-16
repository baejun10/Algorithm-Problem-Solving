#include <iostream>

using namespace std;


int main(){
    short y;
    bool yoon = 0;
    cin >> y;

    if(y%4 == 0 && y%100 !=0) yoon = 1;
    if(y%400 == 0) yoon = 1;
    cout << yoon;
    return 0;
}