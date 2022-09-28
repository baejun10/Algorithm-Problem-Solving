#include <iostream>

using namespace std;
int tmp[500001], k, ans;
int scnt = 0;
void merge(int arr[], int s, int m, int e) {
    int i = s, j = m + 1, t = 0;
    while (i <= m && j <= e) {
        if (arr[i] < arr[j]) {

            tmp[t++] = arr[i++];
        } else {

            tmp[t++] = arr[j++];
        }
    }

    while (i <= m) {

        tmp[t++] = arr[i++];
    }
    while (j <= e) {

        tmp[t++] = arr[j++];
    }
    i = s, t = 0;
    while (i <= e) {
        scnt++;

        if (scnt == k)
            ans = tmp[t];
        arr[i++] = tmp[t++];
    }
}

void merge_sort(int arr[], int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        merge_sort(arr, s, m);
        merge_sort(arr, m + 1, e);
        merge(arr, s, m, e);
    }
}

int main(int argc, char const *argv[]) {
    int n, A[500001];
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    merge_sort(A, 0, n - 1);
    // for (int i = 0; i < n; i++) {
    //     cout << A[i] << " ";
    // }
    if (scnt < k)
        cout << -1;
    else
        cout <<  ans ;
}