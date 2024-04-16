#include <iostream>
#include <stack>
using namespace std;

int main()
{
    
   	int a, b;
 
	// 또는 scanf("%d %d", &a, &b) == 2 로도 가능
	while(scanf("%d %d", &a, &b) != -1) {
		printf("%d\n", a + b);
	}
    
}