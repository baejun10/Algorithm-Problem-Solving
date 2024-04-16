#include <iostream>
#include <string>
using namespace std;


int main()
{
    string s;
    cin >> s;
    for(int i = 'a' ; i <= 'z' ; i++){
        int p = s.find_first_of(i);
        if(p != string::npos)
            printf("%d ",p);
        else
            printf("-1 ");
        
    }
    


}