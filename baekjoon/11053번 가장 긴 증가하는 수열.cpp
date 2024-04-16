#include <iostream>
#include <deque>

using namespace std;

int a[1001][1001] = {};
int main()
{
    int n;
    int p[1001] = {};
    int length,longer = 0;


    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> p[i];
    }
    for(int i = 0; i < n;i++){
        int k = 1;
        a[i][0] = p[i];
        for(int j = 1;p[i+j] > p[i+j-1]; j++){
            a[i][k] = p[i+j];
            k++;
        }
    }
    for(int i = 0 ; i <sizeof(a)/sizeof(a[0]);i++){
        for(int j =  0; j < sizeof(a[i])/sizeof(int);j++){

            if(a[i][j] == 0)
                break;
            cout << a[i][j] <<" ";
        }
        if(a[i][sizeof(a[i])/sizeof(int)] != 0)
            cout << "\n";
    }
    
}