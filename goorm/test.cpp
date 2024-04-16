#include <iostream>
#define MAX 204
using namespace std;
int state[MAX][MAX] = {};
int map[MAX][MAX] = {};
int main() {
	
	int n, k, max = 0;
	cin >> n >> k;
	for(int i = 0 ;i < n; i++){
		for(int j = 0 ;j < n; j++){
			cin >> state[i][j];
		}
	}
	
	return 0;
}
