#include <stdio.h>

long long sum(int *a, int n){
    long long sum = 0;
    for(int i = 0 ; i < n ; i++){
        sum += a[i];
    }
    return sum;
}

int main()
{
    int arr[] = {1,2,3,4,5};
    printf("sum: %d",sum(arr, 5));

}