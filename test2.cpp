#include <iostream>
#include <unordered_set>
using namespace std;

typedef struct {
    int h;
    int m;
} time;

int comp_t(time a, time b) {
    int am = a.h * 60 +a.m;
    int bm = b.h *60 +b.m;
    if(am < bm) return 1;
    else if(am == bm) return 0;
    else if(am > bm) return -1;
}

int main(int argc, char const *argv[]) {
    unordered_set<string> in;

    int ans = 0;
    time s, e, q;

    scanf("%d:%d", &s.h, &s.m);
    scanf("%d:%d", &e.h, &e.m);
    scanf("%d:%d", &q.h, &q.m);

    time t;
    string name;
    while (scanf("%d:%d", &t.h, &t.m) != EOF) {
        cin >> name;
        if (comp_t(t, s) != -1) {
            in.insert(name);
        } else if (comp_t(t, e) != 1 && comp_t(t, q) != -1) {
            if (in.find(name) != in.end()){
                in.erase(name);
                
                ans++;
            }
                
        }
    }
    cout << ans;
}