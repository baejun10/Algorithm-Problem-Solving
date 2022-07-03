#include <iostream>

using namespace std;

int main()
{
    int a, b, v, d, h = 0;
    cin >> a >> b >> v;
    // for(d = 1; h < v; d++){
    //     h += a;
    //     if(h>=v) break;
    //     h -= b;
    // } 시간 초과
    int dayup = a - b;
    d = v/dayup-a;
    if (d < 0) d = 0;
    h = dayup*d;
  
    //printf("d: %d\n",d);
    while( h < v ){
        h += a;
        if(h>=v) break;
        
        h -= b;
        d++;
    }
    printf("%d", d+1);
}