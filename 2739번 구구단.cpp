#include <iostream>

using namespace std;


int main(){
    int n;
    cin >> n;

    for(int i=1;i <10;i++){
        int ans = n*i;
        printf("%d * %d = %d\n",n,i,ans);
    }

    return 0;
}