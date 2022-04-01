#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[10] = {1,7,3,4,0};
    sort(arr,arr+10);
    printf("%d %d",arr[0], arr[9]);
}