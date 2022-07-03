#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int bep = 0;
    if(b>=c){
        printf("-1");
        return 0;
    }
    // for(bep = 1 ; a+(b*bep) >= c*bep; bep++); 
    bep = a/(c-b);
    
    printf("%d", bep+1);
}