#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> arr, ans;
int oarr[1000001];

int main(int argc, char const *argv[]) {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> oarr[i];
        arr.push_back(oarr[i]);
    }
    // set 으로 중복제거 정렬 후 이진탐색으로 시간 아끼기
    // but, distance 함수로 set 인덱스 계산에서 시간 복잡도 n*O(n) 시간초과 발생
    // 다시 vector로 중복 제거하면서 받고 정렬 -> 탐색 자체 반복하므로 시간초과
    // 그래서 일단 입력후 정렬한 뒤 중복제거하기 -> Solve!
    sort(arr.begin(), arr.end()); // nlogn
 
    ans.push_back(arr[0]);
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] != arr[i]) { //O(n) 시간 복잡도로 중복 제거
            // erase 함수의 시간복잡도가 o(n)이므로 그냥 새로운 벡터로 만든다
            ans.push_back(arr[i]);
 
        }
    }
    for (int i = 0; i < n; i++) {
        int p = lower_bound(ans.begin(), ans.end(), oarr[i]) -
                ans.begin(); // n*logn
        cout << p << " ";
    }
}