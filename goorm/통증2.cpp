#include <iostream>
using namespace std;
int main() {
	int n, ans = 0;
	int a, b;
	cin >> n;
    cin >> a >> b;
    ans += n/b; // b가 더 크기 때문에 n을 b로 나눈 나머지만큼만 계산하면 된다.
    n = n%b;
   
    while(n%a != 0){
        n += b;
        ans--;
        if(ans < 0){
            ans = -1;
            break;
        }
    }
    if(ans >= 0)
        ans += n/a;

	cout << ans;
	
}