#include <iostream>

using namespace std;
int n,tcn;

int tcol[16] = {};
int nqueen(int col) {
    int cnt = 0;
    if (col == n) {
        return cnt+1;
    }
    
    for (int i = 0; i < n; i++) {
        bool chk = false;
        for (int j = 0; j < col; j++) {
            tcol[col] = i;
            if (tcol[j] == tcol[col] || (j - col) == (tcol[j] - tcol[col]) ||
                ((j - col) == (tcol[col] - tcol[j]))) {
                chk = true;
                break;
            }
        }
        if(!chk) cnt += nqueen(col+1);
    }
    
    return cnt;
}
int sol(int n) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        tcol[0] = i;
        ans += nqueen(1);
    }
    return ans;
}

int main(int argc, char const *argv[]) {

    cin >> n;
    cout << sol(n);

}