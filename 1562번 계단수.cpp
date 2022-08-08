#include <iostream>

using namespace std;

int n;
int mem[101][10][1 << 11] = {};
bool visit[101][10][1 << 11] = {};
long long int dfs(int prev, int len, int bit)
{
    long long int cnt = 0;

    if (len == n)
    {
        if (bit == ((1 << 10) - 1)) cnt++;
        //cout << bit << endl;
        return cnt;
    }

    else if (len == 0)
    {
        for (int i = 1; i <= 9; i++)
        {
            cnt += dfs(i, len + 1, bit | (1 << i))% (int)1e9;
            
        }
    }
    else
    {
        if (prev == 0)
        {
            if (visit[len][prev][bit] == false)
            {
                mem[len][prev][bit] = dfs(prev + 1, len + 1, bit | (1 << prev + 1));
            }
            cnt += mem[len][prev][bit] % (int)1e9;
            visit[len][prev][bit] = true;
        }
        else if (prev == 9)
        {
            if (visit[len][prev][bit] == false)
            {
                mem[len][prev][bit] = dfs(prev - 1, len + 1, bit | (1 << prev - 1));
            }
            cnt += mem[len][prev][bit] % (int)1e9;
            visit[len][prev][bit] = true;
        }
        else
        {
            if (visit[len][prev][bit] == false)
            {
                mem[len][prev][bit] = dfs(prev + 1, len + 1, bit | (1 << prev + 1));
                mem[len][prev][bit] += dfs(prev - 1, len + 1, bit | (1 << prev - 1));
            }
            cnt += mem[len][prev][bit] % (int)1e9;
            visit[len][prev][bit] = true;
        }
    }
    return cnt %= (int)1e9;
}

int main()
{
    long long int ans = 0;
    cin >> n;

    ans = dfs(0, 0, 0);
    cout << ans;
}