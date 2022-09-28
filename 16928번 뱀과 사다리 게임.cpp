#include <iostream>
#include <algorithm>
#include <queue>
#define next _next
using namespace std;
queue<int> q; 
int d[101];	// 최소 이동 횟수
int next[101];	// 다음 방향 저장
int main() {
    int n, m;	// 사다리,뱀
    cin >> n >> m;
    for (int i=1; i<=100; i++) { // 맵과 거리 배열 초기화
        next[i] = i; // 기본적으로 자기자신을 가리키도록
        d[i] = -1;
    }
    while (n--) { // 사다리
        int x, y;
        cin >> x >> y;
        next[x] = y;
    }
    while (m--) { // 뱀 
        int x, y;
        cin >> x >> y;
        next[x] = y;
    }
    d[1] = 0; // 시작점 이동횟수를 0번으로
    // BFS 탐색 시작
    q.push(1);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i=1; i<=6; i++) {
            int y = x+i;		// 주사위에서 나온 칸 i 만큼 이동
            if (y > 100) continue;	// 100을 넘으면 다음으로
            y = next[y];		// 사다리or뱀이면 해당 칸으로 이동, 일반 칸이면 그대로
            if (d[y] == -1) { // 이동할 곳에 방문하지 않았다면
                q.push(y);
                d[y] = d[x] + 1; // 이동회수 카운트
            }
        }
    }
    cout << d[100] << '\n';
    return 0;
}