#include <iostream>
#define INT_MAX 100000000
// 오버플로우 주의!!!
using namespace std;

// 비트마스킹 + DP
int n;
int w[16][16] = {};
int dp[16][1 << 17] = {}; // int는 16비트 이므로 2^16가지 경우 표현 가능
    // 두번째 축은 비트마스킹 방문한 도시 기록
    // n이 16이하이므로 사용 가능

int dfs(int st, int visited){
    if(visited == (1 << n)-1)//전부 방문시 10000000 - 1 = 11111111
    {
        int t = w[st][0];
        if(t == 0) return INT_MAX;// 오버플로우 발생 가능
        else return t; 
        // 마지막에 출발 도시(원점)으로 복귀
    }
    else if(dp[st][visited] == 0){
        return dp[st][visited];
    }
    int t = INT_MAX;
    for(int i = 0 ; i < n ; i++){
        if((visited & (1 << i)) == 0 && w[st][i] != 0){ // 저장된 값이 다르거나 없으면
            // 괄호 주의!!!!!!! 비교 연산자가 쉬프트 연산자 보다 우선순위 높음 시간 이걸로 날림 ㅋㅋㅋ
            t = min(t, dfs(i, visited | (1 << i)) + w[st][i]); // t값에 가장 작은 가중치 대입
            // st에서 출발해서 i에 도착하는 가중치 + i 이후 dfs            
        }
    }
    dp[st][visited] = t; // 가중치 저장!
    return t;

}

int main()
{
    
    
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> w[i][j];
            if(i == j) w[i][j] = 0; 
        }
    }

    // 시작위치 상관 없음 모든 경우 탐색
    cout << dfs(0, 1 << 0);
}