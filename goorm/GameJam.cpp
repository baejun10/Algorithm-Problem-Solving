#include <string>
#include <iostream>
#include <cstdlib>
#define MAX 204
#define GOORM 0
#define PLAYER 1
using namespace std;
int state[MAX][MAX] = {};
string map[MAX][MAX] = {};
char visit[2][MAX][MAX] = {};
int count[2] = {};
int n;
int move(string dir, int pos[], int player){
    int x = pos[1];
    int y = pos[0];
    int num = stoi(dir.substr(0, dir.size() - 1));
    char ch = dir[dir.size() - 1];
    int dx = 0, dy = 0;
    if(ch == 'U'){
        dy-=num;
    }
    else if(ch == 'D'){
        dy+= num;
    }
    else if(ch == 'L'){
        dx-= num;
    }
    else if(ch == 'R'){
        dx+= num;
    }
    int dp = dx + dy; // 둘 중 하나의 값
    for(int i = 0 ; i < abs(dp); i++){
        if(dx > 0){
            x++;
        }
        else if (dx < 0){
            x--;
        }
        else if(dy > 0){
            y++;
        }
        else if (dy < 0){
            y--;
        }
        //  x, y 경계값 처리
        x = x%n;
        y = y%n;
        if(x < 0){
            x = n + x;
        }
        if(y < 0){
            y = n + y;
        }

        if(visit[player][y][x] == 1){
            return 1;
        }
        else{
            visit[player][y][x] = 1;
            count[player]++;
        }
    }
    
    pos[0] = y;
    pos[1] = x;
    return 0;
}
int main() {
	int player[2] = {};
    int goorm[2] = {};
	int r, c;
    cin >> n;
    cin >> r >> c;
    goorm[0] = r - 1; goorm[1] = c - 1;
    cin >> r >> c;
    player[0] = r - 1; player[1] = c - 1;

    for(int i = 0 ;i < n; i++){
        for(int j = 0 ;j < n; j++){
            cin >> map[i][j];
        }
    }
    // 시작점 방문처리
    visit[0][goorm[0]][goorm[1]] = 1;
    count[0]++;
    while(true){
        int ret = move(map[goorm[0]][goorm[1]], goorm, GOORM);
        if(ret == 1)   break;
        
    }

    // 시작점 방문처리
    visit[1][player[0]][player[1]] = 1;
    count[1]++;
    while(true){
        int ret = move(map[player[0]][player[1]], player, PLAYER);
        if(ret == 1)
            break;
    }

    if(count[0] > count[1]){
        cout << "goorm " << count[0];
    }
    else if(count[0] < count[1]){
        cout << "player " << count[1];
    }
    else{
        cout << "SAME " << count[0];
    }
    
}
