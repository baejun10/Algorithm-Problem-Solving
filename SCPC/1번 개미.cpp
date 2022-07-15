#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

typedef pair<int, int> pi;

void sol(int t){
    int n, ans = 0;
    priority_queue <pi, vector<pi>, greater<pi>> pv;
    vector <int> p, v;
    
    cin >> n;
    for(int i = 0 ;i < n ;i++){
        int k;
        cin >> k;
        p.push_back(k);
    }
    for(int i = 0 ;i < n ;i++){
        int k;
        cin >> k;
        v.push_back(k);
    }
    for(int i = 0 ;i < n ;i++){
        pv.push(make_pair(v[i], p[i])); // 숫자, 위치 순으로 정렬
    }


    for(int i = 0 ; i < n ;i++){
        //printf("%d - %d \n", p[i],  pv.top().second);
        ans += abs(p[i] - pv.top().second);
        pv.pop();
    }
    cout << "Case #"<<t<< endl;
    cout << ans << endl;
    return;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    cin.tie(NULL);

    int t;
    cin >> t;
    for(int i = 1 ; i <= t ; i++){
        sol(i);
    }
}