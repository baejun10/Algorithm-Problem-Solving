#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int e, v;
// 인접리스트
vector<tuple<int, int, long long int>> link;
int t[1000000]; // 유니온 각 트리에 속한 정점 저장

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

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
    int x = get<2>(a);
    int y = get<2>(b);
    return x < y;
}

int mst() {
    int w = 0;
    for (int i = 0; i <= v; i++) {
        t[i] = -1;
    }
    for (auto &el : link) {
        if (!find_union(get<0>(el), get<1>(el))) {
            w += get<2>(el);
            uni(get<0>(el), get<1>(el));
        }
    }
    return w;
}

int main(int argc, char const *argv[]) {

    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        link.push_back(make_tuple(a, b, c));
    }
    sort(link.begin(), link.end(), cmp); // 간선 가중치 적은 순으로 정렬

    cout << mst();
}