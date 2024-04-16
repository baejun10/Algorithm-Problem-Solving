#include <iostream>
using namespace std;
int n;
int M[1002][1002] = {};
int G[1002][1002] = {};
int union_num = 0;
void set_union(int r, int c, int union_num){
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for(int i = 0 ; i < 4; i++){
        int x = c + dir[i][0];
        int y = r + dir[i][1];
        if(x >= 0 && x < n && y >= 0 && y < n){
            if(M[y][x] == 1 && G[y][x] == 0){
                G[y][x] = union_num;
                set_union(y, x, union_num);
            }
        }
    }
}

int main() {
	
    
    int ans = 0;
    cin >> n;
    for(int i = 0 ;i < n; i++){
        for(int j = 0 ;j < n; j++){
            cin >> M[i][j];
        }
    }

    for(int i = 0 ;i < n; i++){
        for(int j = 0 ;j < n; j++){
            if(M[i][j] == 1 && G[i][j] == 0){
                union_num++;
                G[i][j] = union_num;
                set_union(i, j, union_num);
            }
        }
    }
    
    
    cout << union_num;


}