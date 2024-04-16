#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    int prize,max;

    cin >> a >> b >> c;
    if(a == b && b ==c){
        prize = 10000+(a*1000);
    }
    else if(a == b || b == c || c == a){
        if(a == b)
        prize = 1000+a*100;
        else if(b == c)
        prize = 1000+b*100;
        else
        prize = 1000+c*100;
    }
    else{
        max = (a>b)?a:b;
        max = (max>c)?max:c;
        prize = max*100;
    }
    cout << prize;
}