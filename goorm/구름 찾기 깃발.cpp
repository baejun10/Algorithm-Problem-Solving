#include <iostream>
using namespace std;
int arr[1004][1004]  = {};
int n, k;
int count_flag(int x, int y){
	int dy[4] = {1, -1, 0};
	int dx[4] = { 0, 1, -1};
	int cnt = 0;
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0; j < 3; j++){
			// 인덱스 밖 처리, + 제자리 예외
			if(x+dx[i] < 0 || x+dx[i] > n || y+dy[j] < 0 || y+dy[j] > n || (dx[i] == 0 && dy[j] == 0)) continue;
			// 지뢰 카운트
			if(arr[x+dx[i]][y+dy[j]] == 1) cnt++;
		}
	}
	return cnt;
}

int main() {
	
	cin >> n >> k;
	int res = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0; j < n; j++){
			cin >> arr[i][j];
		}}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0; j < n; j++){
			if(arr[i][j] == 0){
				if(count_flag(i, j) == k) res++;
			}
		}
	}
	cout << res;
}