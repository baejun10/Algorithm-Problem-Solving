#include <iostream>
#include <unordered_set>
using namespace std;

typedef struct {
    int h;
    int m;
} time;

int comp_t(time a, time b) {
    if (a.h < b.h)
        return 1;
    else if (a.h == b.h) {
        if (a.m < b.m)
            return 1;
        else if (a.m == b.m)
            return 0;
        else
            return -1;
    } else
        return -1;
}

int main(int argc, char const *argv[]) {
    unordered_set<string> in;
    // unordered_set <string> out;
    int ans = 0;
    time s, e, q;

    scanf("%d:%d", &s.h, &s.m);
    scanf("%d:%d", &s.h, &s.m);
    scanf("%d:%d", &q.h, &q.m);

    time t;
    string name;
    while (true) {
        scanf("%d:%d %s", &t.h, &t.m, name);
        if (comp_t(t, s) != -1) {
            in.insert(name);
        } else if (comp_t(t, e) != 1 && comp_t(t, q) != -1) {
            // out. insert(name);
            if (in.find(name) != in.end()){
                in.erase(name);
                ans++;
            }
                
        }
    }
    cout << ans;
}