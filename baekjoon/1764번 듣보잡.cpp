#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    static set<string> unheard_seen;
    static unordered_set<string> name_set;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n + m; i++) {
        string name;
        cin >> name;
        if (i < n) {
            // 첫 번째 그룹은 집합에 추가
            name_set.insert(name);
        } else {
            // 두 번째 그룹은 집합에서 찾기
            if (name_set.find(name) != name_set.end()) {
                unheard_seen.insert(name); // 중복된 이름을 듣보잡 set에 삽입
            }
        }
    }
    cout << unheard_seen.size() << '\n';
    for(const auto& name : unheard_seen){
        cout << name << '\n';
    }
}