#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int n, m;
char adj[51][51];
// 인접행렬
vector<pair<int, int>> link;
int t[10000]; // 유니온 각 트리에 속한 정점 저장

int find(int x) {
    if (t[x] < 0)
        return x;

    else
        return t[x] = find(t[x]);

    // dfs로 루트 탐색 + 경로 압축 (바로 최초 루트 저장해서)
}

bool find_union(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return true;
    else
        return false;
}

void uni(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    if (t[x] < t[y]) {
        t[x] += t[y];
        t[y] = x;
    } else {
        t[y] += t[x];
        t[x] = y;
    }
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a > b;
}

int mst() {
    int end_zero= 0, end_one = 0, end_end=0;
    for (int i = 0; i <= n; i++) {
        t[i] = -1;
    }
    for (auto &el : link) {
        if (!find_union(el.first, el.second)) {
            uni(el.first, el.second);
            if(el.second == 0) end_zero++;
            else if(el.second == 1) end_one++;
            else if(el.second == n-1) end_end++;
        }
    }
    cout << end_zero << " " << end_one << " " << end_end;
}

int main(int argc, char const *argv[]) {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
            if(adj[i][j] == 'Y'){
                link.push_back(make_pair(i, j));
            }
        }
    }

    sort(link.begin(), link.end(), cmp); // 간선 가중치 적은 순으로 정렬
    mst();
}