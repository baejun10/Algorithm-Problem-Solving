#include <iostream>

using namespace std;

int main()
{
    int n, n2,f,e,nex = -1,cy=0;
    cin >> n;
    n2 = n; // 초기값 저장

    while(n2 != nex){
        if(n<10){
            n= n*10+n;
            cy++;
            if(n==n2)
                break;
        }
            
        f = n/10;
        e = n%10;

        nex = e*10+((f+e)%10);
        n = nex;
        //cout << nex << endl;
        cy++;
        
    }
    cout << cy;
    
}