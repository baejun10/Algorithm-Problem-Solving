#include <iostream>

using namespace std;

int is_exist(int plug[], int in, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (plug[i] == in)
            return i + 1;
    }
    return 0;
}
int main()
{
    int ans = 0;
    int n, k, plug[100] = {0,},list[100] = {0,};
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> list[i];
    }
    // 남은 스케줄에 없을경우 우선적으로 빼기 가까운 스케줄에 있을수록 나중에 빼기
    //그리디

    for (int i = 0; i < k; i++)
    { //스케줄 list 실행
        bool in = false;
        if (is_exist(plug, list[i], n))
        {

            in = true;
        } // 이미 존재할 경우 스킵
        if (in == true)
            continue;
        for (int j = 0; j < n; j++)
        {
            if (plug[j] == 0)
            {
                plug[j] = list[i];
                in = true;

                break;
            }
        } // plug 빈곳 있으면 삽입
        if (in == true)
            continue;

        // 삽입된 플러그중 가장 스케줄 나중에 등장하는것 뽑고 삽입하기

        int max = 0;
        int pulloff = 0;
        int cnt[100] = {
            0,
        };
        for (int j = 0; j < n; j++)
        {
            for (int l = i + 1; l < k; l++)
            {
                if (plug[j] == list[l])
                {
                    cnt[j] = l;
                    if (max < l)
                    {
                        max = l;
                        pulloff = j;
                    }
                    break;
                }
            }
            if (cnt[j] == 0)
            { //등장하지 않을경우 최우선으로 뽑기
                pulloff = j;
                break;
            }
        }
        // for(int j = 0 ; j < n; j++){
        //     if(cnt[j] == 0){ //등장하지 않을경우 최우선으로 뽑기
        //         pulloff = j;
        //         break;
        //     }
        // }
        
        plug[pulloff] = list[i];

        ans++;
    }

    cout << ans;
}