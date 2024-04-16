#include <iostream>

using namespace std;

int main()
{
    int t;
    int h, w, n, ans;
    int floor, next; 
    
    cin >> t;

    for(int i = 0 ;i < t; i++){
        cin >> h >> w >> n;
        
        floor = n % h;
        if(n % h == 0){
            floor = h;
            next = n/h;
        } 
        else{
            next = n/h + 1;
        }
        ans = floor*100;
        ans += next;
        cout << ans << endl;
    }
}