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
	
	// 폭탄 투하
	int r, c;
	int dir[4][2] ={{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
	for(int i =0  ;i < k ;i++){
		cin >> r >> c;
		for(int j =0 ;j < 4; j++){
			int x = c + dir[j][0] - 1;
			int y = r + dir[j][1] - 1;
			if(state[y][x] == '0'){
				map[y][x]++;
			}
			else if(state[y][x] == '@'){
				map[y][x] += 2;
			}
			else if(state[y][x] == '#'){
				//Do nothing
			}
		}
	}
	for(int i = 0 ;i < n;i++){
		for(int j = 0 ;j < n; j++){
			max = max < map[i][j] ? map[i][j] : max;
		}
	}
	cout << max;
	return 0;
}
