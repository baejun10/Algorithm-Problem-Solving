#include <iostream>
#include <algorithm>
using namespace std;

typedef struct pos{
    int x;
    int y;
}pos;



bool cmp(pos a, pos b){
    if(a.x < b.x) return 1;
    else if(a.x == b.x){
        if(a.y <= b.y) return 1;
        else return 0;
    }
    else return 0;
}
int main(int argc, char const *argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    pos p[100000];

    cin >> n;
    for(int i = 0 ;i < n; i++){
        cin >> p[i].x >> p[i].y;
    }
    sort(p, p+n, cmp);
    for(int i = 0 ;i < n; i++){
        cout << p[i].x << " " << p[i].y << "\n";
    }
}