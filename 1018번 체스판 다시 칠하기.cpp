#include <iostream>

using namespace std;
char board[50][50] = {};
int n, m;
int cnt_wrong(char cutboard[][8]){
    int a1 = 0, a2 = 0;
    for(int i = 0 ; i < 8 ; i++){//행
        for(int j = 0 ; j < 8 ; j++){//열
        //cout << cutboard[i][j];
            if(i%2 == 0 && j%2 == 0 && cutboard[i][j] != 'W') a1++;
            else if(i%2 == 0&& j%2 == 1 && cutboard[i][j] != 'B') a1++;
            else if(i%2 == 1&& j%2 == 0 && cutboard[i][j] != 'B') a1++;
            else if(i%2 == 1&& j%2 == 1 && cutboard[i][j] != 'W') a1++;

            if(i%2 == 0 && j%2 == 0 && cutboard[i][j] != 'B') a2++;
            else if(i%2 == 0&& j%2 == 1 && cutboard[i][j] != 'W') a2++;
            else if(i%2 == 1&& j%2 == 0 && cutboard[i][j] != 'W') a2++;
            else if(i%2 == 1&& j%2 == 1 && cutboard[i][j] != 'B') a2++;
        }
        //cout << "\n";
    }
    return a1 > a2 ? a2 : a1;
}

void mk_cut(int x, int y, char cutboard[][8]){
    for(int i = 0 ; i < 8 ; i++){//행
        for(int j = 0 ; j < 8 ; j++){//열
            cutboard[i][j] = board[x+i][y+j];
        }
    }
}
int main()
{
    
    char cutboard[8][8] = {};
    int a1, a2;
    int min ;
    cin  >> n >> m;
    for(int i = 0 ; i < n ; i++){//행
        for(int j = 0 ; j < m ; j++){//열
            cin >> board[i][j];
        }
    }

    for(int i = 0 ; i <= n-8 ; i++){//행
        for(int j = 0 ; j <= m-8 ; j++){//열
            mk_cut(i, j, cutboard);
            int w = cnt_wrong(cutboard);
            if(i == 0 && j == 0 || min > w) min = w;
        }
    }
    cout <<  min;
    
}