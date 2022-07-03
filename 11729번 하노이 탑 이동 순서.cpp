#include <iostream>
#include <math.h>
using namespace std;

void hanoi_mov(int n, int start, int end){
    if(n == 1){
        printf("%d %d\n",start, end);
        return;
    }
    int mid = 6 - start - end; // start, end빼고 남은거 한개
    hanoi_mov(n-1, start, mid);
    printf("%d %d\n",start, end);
    hanoi_mov(n-1, mid, end);
}

int main()
{   
    int n;
    scanf("%d", &n);
    printf("%.f\n",pow(2,n)-1 );

    hanoi_mov(n,1, 3);

}