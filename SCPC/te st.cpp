#include <iostream>
#include <string>

using namespace std;
int plist[500000] = {};

int fpsum(int n, int start, int idx, int cut){
    // n: 목표값, start 시작 인덱스, idx 수열 원소 개수
    int cnt = 0;
    int sum = 0;
    int end = start;
    while(start <= idx){
        while(sum < n && end < idx){
            sum += plist[end];
            end++;
        }
        if(sum == n){
            return fpsum(n, end, idx, cut)+1;
        } 
        else{ // 부분합 더 클 경우
            return 0;
        }
        //cout << sum << endl;
    }
    
}

void sol(int t)
{
    int start= 0, end = 0, cnt = 0;
    int n, k, sum = 0;
    
    cin >> n >> k;
    int idx = n;
    for(int i = 0 ;i < idx; i++){
        cin >> plist[i];
        sum += plist[i];
    }
    cout << "Case #" << t+1 << endl; 
    cout << fpsum(sum/k, 0, idx, k) << endl;
    
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);

    int t;
    cin >> t;
    for(int i = 0 ; i < t; i++){
        sol(i);
    }
    
    

}