#include <iostream>

using namespace std;

int n, m, ans = 0;
int party_mem[50][50] = {}; // i번째 파티 멤버 명단
int true_num;
bool true_link[50] = {false};

void union_truth(int mem[], bool ntrue[])
{
    for (int i = 0; i < m; i++){
        bool flag = false;
        for (int j = 0; j < mem[i]; j++)
        {

            if (ntrue[party_mem[i][j]] == true)
            {
                flag = true;
                break;
            }
        }
        if (flag) // 진실아는 사람과 겹칠 시
        {
            bool newtrue[50] = {};
            for (int j = 0; j < mem[i]; j++)
            {
                 // 진실 아는 멤버와 겹침 표시
                if (true_link[party_mem[i][j]] == false)
                    newtrue[party_mem[i][j]] = true;
                true_link[party_mem[i][j]] = true;
            }
            union_truth(mem, newtrue); // 재귀 새롭게 추가된 truelink에서 또 탐색 /분할정복인가?
        }
    }
}

int main()
{

    cin >> n >> m;
    cin >> true_num;
    for (int i = 0; i < true_num; i++)
    {
        int t;
        cin >> t;
        true_link[t] = true;
    }
    int mem[50] = {}; // i+1번째 파티 멤버 수

    for (int i = 0; i < m; i++)
    {

        cin >> mem[i];
        for (int j = 0; j < mem[i]; j++)
        {
            cin >> party_mem[i][j];
        }
    }
    // 진실 아는 사람 없는지 검사 + 한번 구라치면 그 멤버에게 계속구라
    // 따라서 구라칠 멤버와 진실을 아는 멤버가 파티에서 겹치면 안됨
    union_truth(mem, true_link);

    for (int i = 0; i < m; i++)
    { // i+1번째 파티에서
        bool known = false;
        for (int j = 0; j < mem[i]; j++)
        { // i+1번째 파티의 멤버 수만큼 반복
            // 진실 아는 사람 없는지 검사 + 한번 구라치면 그 멤버에게 계속구라
            // 따라서 구라칠 멤버와 진실을 아는 멤버가 파티에서 겹치면 안됨
            if (true_link[party_mem[i][j]] == true)
                {
                    known = true;
                    break;
                }
            if (known == true)
                break;
        }
        if (known == false)
            ans++;
    }
    cout << ans;
}