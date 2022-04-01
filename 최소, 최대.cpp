#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000001] = {};

int main()
{
    int n;
    
    scanf("%d",&n);
    for(int i = 0 ; i < n ;i++){
        scanf("%d",&arr[i]);
    }

    sort(arr,arr+n);
    printf("%d %d",arr[0],arr[n-1]);

}