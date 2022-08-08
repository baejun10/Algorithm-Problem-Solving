#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int n, sum = 0, mid;
    int max = 0, maxn = 0;
    vector <int> nvec, mfq;
    int ncnt [2][4001] = {};
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int t;
        cin >> t;
        nvec.push_back(t);
        sum += t;
        if(t < 0) ncnt[1][-t]++;
        else ncnt[0][t]++;

    }
    for(int i = 0 ; i <= 4000 ; i++){
        if(max < ncnt[0][i]){
            max = ncnt[0][i];
            maxn = i;
            mfq.clear();
            mfq.push_back(i);
        }
        else if(max == ncnt[0][i]){
            mfq.push_back(i);
        }
    }
    for(int i = 1 ; i <= 4000 ; i++){
        if(max < ncnt[1][i]){
            max = ncnt[1][i];
            mfq.clear();
            mfq.push_back(-i);
        }
        else if(max == ncnt[1][i]){
            mfq.push_back(-i);
        }
    }
    sort(nvec.begin(), nvec.end());
    sort(mfq.begin(), mfq.end());
    if(mfq.size() >= 2) maxn = mfq[1];
    else maxn = mfq[0];

    mid = nvec[nvec.size()/2];

    double avg = (double)sum/n; // float은 안되고 double은 된다... 정확도 이슈 웬만하면 double 쓰자
    if(avg > -0.5 && avg < 0) avg = -avg;
    printf("%.0lf\n", avg); // -0.333... 반올림시 -0이 되는 오류!
    cout << mid << endl;
    cout << maxn << endl;
    cout << nvec.back()-nvec.front() << endl;


}