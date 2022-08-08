#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int n, c;
// parametric search

int check(int gap, vector<int> vec) {
    int now = 0;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (vec[i] - vec[now] >= gap) {
            cnt++;
            now = i;
        }
    }
    if (cnt >= c)
        return 1;
    else
        return 0;
}

int min_gap(vector<int> vec) {
    int min = vec[1] - vec[0];
    for (int i = 1; i < n - 1; i++) {
        int t = vec[i + 1] - vec[i];
        if (t < min) {
            min = t;
        }
    }
    return min;
}
int main() {

    vector<int> coord;
    cin >> n >> c;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        coord.push_back(t);
    }
    // 이분탐색을 위해 정렬
    sort(coord.begin(), coord.end()); // 좌표 정렬
    // parametric search
    int min = min_gap(coord);
    int max = coord.back() - coord.front(); // 집 최대 거리
    int ans = 0;
    int left = min, right = max;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(mid, coord)) { // 조건 만족
            left = mid + 1;
            ans = mid;

        } else { // 불만족
            right = mid - 1;
        }
    }

    cout << ans;
}