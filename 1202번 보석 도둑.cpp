#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    priority_queue<pair<int, int>> jw; // ���� ���� ���� �⺻�� ��������
    multiset<int> bw;                  // ����� �ִ� ����
    
    for (int i = 0; i < n; i++)
    {
        int price;
        int weight;
        cin >> weight >> price;
        jw.push(make_pair(price, weight));
    }
    for (int i = 0; i < k; i++)
    {
        int b;
        cin >> b;
        bw.insert(b);
    }
    //���� ���� ��Ƽ������ ��ü��
    // make_heap(bw.begin(), bw.end()); //�� �����
    // sort_heap(bw.begin(), bw.end());
    // sort(bw.begin(), bw.end()); // �ð� �ʰ� �־� o(n^2)�̶�

    long long int np = 0; // �� ���� ����

    for (int i = 0; i < n; i++)
    {
        if (bw.empty())
            break;

        int tp = jw.top().first;  // ���� ����
        int tw = jw.top().second; // ��������
        int tb = *bw.rbegin();    // ���� ������ ������ �ִ� ����
        if (tb >= tw)
        { // ���� ���� ����
            // ���� ���� ���� �� �ּڰ� ã��
            auto tbiter = bw.lower_bound(tw); // set�� ���� lowerbound ���
            // int rw = tb - tw;
            // if (rw > 0)
            //     bw.push(rw);
            // ���� ���� �켱����ť�� �ٽ� �ֱ�(����� ���� �ִ� �Ѱ� �̹Ƿ� �ϸ� �ȵ�)
            np += tp;
            jw.pop();
            bw.erase(tbiter);
            // bw.erase(tbi + bw.begin()); //Vector�� erase�� �ð� �ʰ��� ���� O(N)�� �ð��� �ɸ�
        }
        else
        { // ���� ���� �Ұ� ���� ����
            jw.pop();
        }
    }
    cout << np;
}