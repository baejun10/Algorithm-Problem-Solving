#include <iostream>

using namespace std;

int main()
{
    int n, i = 0, d = 0, s =0;
    int r, c;
    cin >> n;
    for(d = 1 ; s < n ; d++){
        s+= d;
        i++;
    }
    //printf("s: %d, d: %d, i: %d\n",s, d, i);
    int dif = s - n;
    if(!(i%2)){//짝수일때
        r = i - dif;
        c = 1 + dif;
    }
    else{
        r = 1 + dif;
        c = i - dif;
    }
    printf("%d/%d", r, c);



}