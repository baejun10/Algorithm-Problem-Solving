#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    priority_queue<pair<int, int>> jw; // 보석 가격 무게 기본값 내림차순
    multiset<int> bw;                  // 가방당 최대 무게
    
    for (int i = 0; i < n; i++)
    {
        int price;
        int weight;
        cin >> weight >> price;
        jw.push(make_pair(price, weight));
    }
    for (int i = 0; i < k; i++)
    {
        int b;
        cin >> b;
        bw.insert(b);
    }
    //정렬 과정 멀티셋으로 대체됨
    // make_heap(bw.begin(), bw.end()); //힙 만들기
    // sort_heap(bw.begin(), bw.end());
    // sort(bw.begin(), bw.end()); // 시간 초과 최악 o(n^2)이라서

    long long int np = 0; // 총 현재 가격

    for (int i = 0; i < n; i++)
    {
        if (bw.empty())
            break;

        int tp = jw.top().first;  // 보석 가격
        int tw = jw.top().second; // 보석무게
        int tb = *bw.rbegin();    // 수용 가능한 가방의 최대 무게
        if (tb >= tw)
        { // 가방 수용 가능
            // 수용 가능 가방 중 최솟값 찾기
            auto tbiter = bw.lower_bound(tw); // set은 전용 lowerbound 사용
            // int rw = tb - tw;
            // if (rw > 0)
            //     bw.push(rw);
            // 남은 공간 우선순위큐에 다시 넣기(가방당 보석 최대 한개 이므로 하면 안됨)
            np += tp;
            jw.pop();
            bw.erase(tbiter);
            // bw.erase(tbi + bw.begin()); //Vector의 erase는 시간 초과의 원인 O(N)의 시간이 걸림
        }
        else
        { // 가방 수용 불가 보석 포기
            jw.pop();
        }
    }
    cout << np;
}