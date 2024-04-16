#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int k, n;
    int cable[10001] = {};
    cin >> k >> n;
    for (int i = 0; i < k; i++)
    {
        cin >> cable[i];
    }

    // 최적화 문제 parametric search로 해결 최댓값 찾는 최적화
    // 순차적으로 증가하면서  x, 이분 탐색으로 노가다하면서 조건 만족 확인
    long long left = 1;;
    long long right = *max_element(cable, cable + k);
    int ans = 0;
    while (left <= right)
    {
        long long total = 0;
        long long mid = (left + right) / 2;
        for (int i = 0; i < k; i++)
        {
            total += cable[i] / mid; 
        }

        if(total >=n){ // 조건 만족시 큰쪽에서 탐색
            left = mid + 1;
            ans = mid;
        }
        else{ // 조건 불만족시 작은쪽에서 탐색
            right = mid - 1;
        }
    }

    cout << ans;
}