#include <iostream>

using namespace std;
int n, m, k;
int narr[1000001];
long long int tree[4000000];
long long int make_tree(int start, int end, int node) {
    if (start == end)
        return tree[node] = narr[start];
    int mid = (start + end) / 2;
    return tree[node] = (make_tree(start, mid, node * 2) *
                         make_tree(mid + 1, end, node * 2 + 1)) %
                        1000000007; // 구간 곱
}
long long int update_tree(int idx, int val, int left, int right, int node) {
    if (idx > right || idx < left)
        return tree[node];
    if (left == right)
        return tree[node] = val;
    int mid = (left + right) / 2;
    return tree[node] = (update_tree(idx, val, left, mid, node * 2) *
                         update_tree(idx, val, mid + 1, right, 2 * node + 1)) %
                        1000000007;
}
long long int range_mul(int left, int right, int node, int start, int end) {
    // start, end : 구간 범위
    // left, right 구간 계산하는 index
    //  segment tree를 사용하여 시간복잡도를 O(logn)으로 줄인다.
    if (start > right || end < left) // 범위 이탈
        return 1;
    if (left >= start && right <= end) //범위 내
        return tree[node];
    int mid = (left + right) / 2;
    return (range_mul(left, mid, node * 2, start, end) *
            range_mul(mid + 1, right, node * 2 + 1, start, end)) %
           1000000007;
}
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> narr[i]; // 1부터 인덱스 시작
    }
    make_tree(1, n, 1); // segment tree 생성

    for (int i = 0; i < m + k; i++) {
        int a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        if (a == 1) {
            narr[b] = c;
            //make_tree(1, n, 1); // 전체 tree 재성생해서 seg tree update 이러면 시간초과
            update_tree(b, c, 1, n, 1);
        } else if (a == 2) {
            cout << range_mul(1, n, 1, b, c) << endl;
        }
    }
}