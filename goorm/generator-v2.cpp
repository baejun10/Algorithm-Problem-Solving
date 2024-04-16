#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int M[1002][1002] = {};
int G[1002][1002] = {};
int union_num = 0;
int danji[40] = {};

int main() {
    int n, k;
    cin >> n >> k;

    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> M[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (M[i][j] != 0 && G[i][j] == 0) {
                int cnt = 1;
                union_num++;
                G[i][j] = union_num;

                queue<pair<int, int>> q;
                q.push({i, j});

                while (!q.empty()) {
                    pair<int, int> curr = q.front();
                    q.pop();

                    int r = curr.first;
                    int c = curr.second;

                    for (int k = 0; k < 4; k++) {
                        int x = c + dir[k][0];
                        int y = r + dir[k][1];

                        if (x >= 0 && x < n && y >= 0 && y < n) {
                            if (M[y][x] == M[r][c] && G[y][x] == 0) {
                                G[y][x] = union_num;
                                cnt++;
                                q.push({y, x});
                            }
                        }
                    }
                }
                if(cnt >= k)
                    danji[M[i][j]]++;
            }
        }
    }
    
    int max = 0;
    int ans;
    for (int i = 1; i <= 30; i++) {
        if(max <= danji[i]){
            max = danji[i];
            ans = i;
        }
    }
    cout << ans;
    

    return 0;
}
