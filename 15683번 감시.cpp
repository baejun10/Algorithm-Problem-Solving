#include <iostream>
#include <vector>
using namespace std;

char arr[8][8] = {};
char carr[8][8] = {};
int blindmin = INT_MAX;
int n, m;
vector <pair<int, int>> dir = {{0,1}, {0,-1}, {-1,0}, {1, 0}}; // 상하좌우

void init_arr(){
    for(int i = 0 ; i < n ;i++){
        for(int j = 0 ; j < m ; j++){
            carr[i][j] = arr[i][j];
        }
    }
}

void draw_area(int x, int y, pair<int, int> dir){
    while(true)
    {
        x = x + dir.first;
        y = y + dir.second;
        if(x >= m || x < 0) break;
        if(y >= n || y < 0) break;

        if(!(arr[y][x] <= 5 && arr[y][x] > 0)) continue; // cctv 위치는 안그림

        arr[y][x] = '#';

    }
}

int cnt_blind(char arr[][8]){
    int cnt = 0;
    for(int i = 0 ; i < n ;i++){
        for(int j = 0 ; j < m ; j++){
            if(arr[i][j] == 0) cnt++;
        }
    }
    return cnt;
}

void cam_dfs(int idx){
    if(idx == 1) init_arr();
    if(idx == m*n-1){
        int ret = cnt_blind(carr);
        blindmin = blindmin > ret ? ret : blindmin;
        cout << ret << endl;
        init_arr();
        return;
    }
    int x = idx % m;
    int y = idx / m;
    if(y % 6 == 0) y++;

    for(int i = y ; i < n ; i++){
        for(int j = x ; j < m ; j++){
            switch(carr[i][j]){
                case 1:
                    // 상 하 좌 우
                    draw_area(j, i, dir[0]);
                    cam_dfs(idx+1);

                    draw_area(j, i, dir[1]);
                    cam_dfs(idx+1);

                    draw_area(j, i, dir[2]);
                    cam_dfs(idx+1);

                    draw_area(j, i, dir[3]);
                    cam_dfs(idx+1);
                    break;
                case 2:
                //상하
                    draw_area(j, i, dir[0]);
                    draw_area(j, i, dir[1]);
                    cam_dfs(idx+1);
                //좌우
                    draw_area(j, i, dir[2]);
                    draw_area(j, i, dir[3]);
                    cam_dfs(idx+1);
                    break;
                case 3:
                //상우
                    draw_area(j, i, dir[0]);
                    draw_area(j, i, dir[3]);
                    cam_dfs(idx+1);
                //우하
                    draw_area(j, i, dir[3]);
                    draw_area(j, i, dir[2]);
                    cam_dfs(idx+1);
                //하좌
                    draw_area(j, i, dir[1]);
                    draw_area(j, i, dir[2]);
                    cam_dfs(idx+1);
                //좌상
                    draw_area(j, i, dir[3]);
                    draw_area(j, i, dir[0]);
                    cam_dfs(idx+1);
                    break;
                case 4:
                    for(int k = 0 ; k < 4 ; k++){
                        draw_area(j, i, dir[k]);
                        draw_area(j, i, dir[(1+k)%4]);
                        draw_area(j, i, dir[(2+k)%4]);
                        // 나머지  0 1 2, 1 2 3, 2 3 0, 3 0 1
                        cam_dfs(idx+1);
                    }
                    break;
                case 5:
                    draw_area(j, i, dir[0]);
                    draw_area(j, i, dir[1]);
                    draw_area(j, i, dir[2]);
                    draw_area(j, i, dir[3]);
                    cam_dfs(idx+1);
                    break;

                default:
                    break;
            }
        }
    }
    return ;
}




int main()
{
    
    
    cin >> n >> m; // n: 세로, m: 가로

    for(int i = 0 ; i < n ;i++){
        for(int j = 0 ; j < m ; j++){
            cin >> arr[i][j];
        }
    }
    cam_dfs(0);
    cout << blindmin;
}