#include <iostream>

using namespace std;

int main()
{
    int n, i, ac = 0;
    cin >> n;
    for(i = 1 ; (n-1)>ac ; i++){
        ac += 6*i;
    }
    printf("%d", i);
}