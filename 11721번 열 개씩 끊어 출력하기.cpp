#include <iostream>

using namespace std;

int main()
{
    int it,s = 0;
    string in;
    cin >> in;
    if(!in.length()%10){
        it = in.length()/10+1;
    }
    else it = in.length()/10;

    for(int k = 0 ; k <= it; k++){
        for(int i = s ; i < 10+s ; i++){
            if(i >= in.length())
                break;
            cout << in.at(i);
        }
        s+=10;
        cout << "\n";
    }
}