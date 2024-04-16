#include <iostream>

using namespace std;


int main(){
    int sc;
    cin >> sc;

    if(sc>89)   cout << "A";
    else if(sc>79)  cout << "B";
    else if(sc>69) cout << "C";
    else if(sc>59) cout << "D";
    else cout << "F";


    return 0;
}