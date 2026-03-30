#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int arr[100][100] = {0, };
    int x, y;
    // input 조건을 보면 수의 범위가 자연수 이므로, 좌표평면을 격자 형태로 나타내서 넓이를 계산할 수 있다.
    //input loop
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        // input은 좌측아래 꼭지점 좌표
        for (int j = x; j < x+10; j++) {
            for (int k = y; k < y+10; k++) {
                arr[j][k] = 1;
            }
        }
    }

    int result = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (arr[i][j] == 1) {
                result++;
            }
        }
    }
    cout << result << endl;

    return 0;
}
