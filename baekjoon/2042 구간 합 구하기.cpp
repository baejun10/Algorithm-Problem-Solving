#include <iostream>
using namespace std;

long long int narr[1000001];
long long int tree[4000000];

long long int make_tree(long long int tree[], int start, int end, int node) {
    if (start == end){
        return tree[node] = narr[start];
    }
    int mid = (start + end) / 2;

    return tree[node] = make_tree(tree, start, mid, node * 2) + make_tree(tree, mid + 1, end, node * 2 + 1);
}

long long int update_tree(long long int tree[], long long int idx, long long int val, int start,
                          int end, int node) {
    if (idx > end || idx < start)
        return tree[node];
    if (start == end)
        return tree[node] = val;
    int mid = (start + end) / 2;

    return tree[node] = update_tree(tree, idx, val, start, mid, node * 2) +
                        update_tree(tree, idx, val, mid + 1, end, node * 2 + 1);
}

long long int query(long long int tree[], long long int left, long long int right, int start, int end, int node ){
    if (left <= start && end <= right){
        return tree[node];
    }
    else if(start > right || end < left){
        return 0;
    }
    int mid = (start + end) / 2;
    return query(tree, left, right, start, mid, node * 2) + query(tree, left, right, mid + 1, end, node * 2 + 1);
        
}

int main() { 
    int n, m, k;

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> narr[i]; 
    }
    make_tree(tree, 0, n - 1, 1); // segment tree 생성

    for (int i = 0; i < m + k; i++) {
        long long int a = 0, b = 0, c = 0; // 값 범위 주의 하여 타입 설정
        cin >> a >> b >> c;
        if (a == 1) {
            // b 번째 인덱스에 c 값으로 업데이트
            update_tree(tree, b-1, c, 0, n - 1, 1);
        }
        else if (a == 2) {
            // (b, c) 구간 합 출력
            cout << query(tree, b-1, c-1, 0, n-1, 1) << endl;
        }
    }

}