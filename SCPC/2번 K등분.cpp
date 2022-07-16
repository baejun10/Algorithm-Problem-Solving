#include <iostream>
#include <string>
#include <set>
#include <map>
#include <utility>
using namespace std;
int plist[500000] = {};


int fpsum(int n, int start, int idx, int divc, int div){
    // n: 목표값, start 시작 인덱스, idx 수열 원소 개수
    map <pair<int, int>, int> mem;
    int cnt = 0;
    int sum = 0;
    int end = start;
    if(divc < div) return 0;
    if(end >= idx){
        if(divc == div) return 1;
        else return 0;
    }
    while(end < idx){
        sum += plist[end];
        end++;
        if(sum == n){
            if(mem.count(make_pair(end, div+1))){
                cnt+= mem.find(make_pair(end, div+1))->second;
            }
            else{
                int tcnt = fpsum(n, end, idx, divc, div+1);
                mem.insert(make_pair(make_pair(end, div+1), tcnt));
                cnt += tcnt;
            }
        } 
    }
    return cnt;
        //cout << sum << endl;

    
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
    cout << fpsum(sum/k, 0, idx, k, 0) << endl;
    
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0 ; i < t; i++){
        sol(i);
    }
    

    // 부분합 알고리즘 투 포인터

    

}