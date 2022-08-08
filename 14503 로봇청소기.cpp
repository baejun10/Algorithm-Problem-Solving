#include <iostream>

using namespace std;

int main()
{
    int map[51][51] = {};
    int n, m;
    int r, c, d;
    int clean = 0;
    cin >> n >> m;
    cin >> r >> c >> d;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
    bool end = 0;

    while (true)
    {

        if(end == true) break;
        if(map[r][c] != 2){

            map[r][c] = 2;
            clean++;
        }
        
        if(map[r+1][c] != 0 && map[r-1][c] != 0 && 
        map[r][c+1] != 0 && map[r][c-1] != 0)
        { // 동서남북 다막힘
            switch (d)
            {
            case 0:
                if(map[r+1][c] != 1){
                    r++;
                }
                else {
                    end = true;
                }
                break;
            case 1:
                if(map[r][c-1] != 1){
                    c--;
                }
                else end = true;
                break;
            case 2:
                if(map[r-1][c] != 1){
                    r--;
                }
                else end = true;
                break;
            case 3:
                if(map[r][c+1] != 1){
                    c++;
                }
                else end = true;
                break;
            }
        }
        else{
            if(d == 0) d = 3;
            else d--;
            switch (d)
            {
                case 0:
                    if(map[r-1][c] == 0){
                        r--;
                    }
                    continue;

                case 1:
                    if(map[r][c+1] == 0){
                        c++;
                    }
                    continue;

                case 2:
                    if(map[r+1][c] == 0){
                        r++;
                    }
                    continue;

                case 3:
                    if(map[r][c-1] == 0){
                        c--;
                    }
                    continue;

            }
            
            
        }
        
    }
    cout << clean;
}