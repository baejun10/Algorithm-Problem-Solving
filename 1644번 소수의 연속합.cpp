#include <iostream>
#include <string>

using namespace std;
bool arr[4000001] = {};
int plist[4000001] = {};
int idx = 0;

void is_prime(int p){
    arr[0] = 1;
    arr[1] = 1;
    for (int w = 2; w <= p; w++) {
		if (arr[w] == 1) {//체로 걸러진다면 돌아가기
			continue;
		}
		for (int e = 2; e * w <= p ; e++) {//w(소수)의 배수를 거르기 w는 제외
			arr[w * e] = 1;
		}
	} // 0이 소수
    
    for(int i = 0 ;i < 4000001 ; i++){
        if(arr[i+1] == 0){
            plist[idx] = i+1;
            idx++;
        }
    }
}



int main()
{
    int start= 0, end = 0, cnt = 0;
    int n;
    is_prime(4000000);
    cin >> n;
    

    // 부분합 알고리즘 투 포인터
    int sum = 0;
    while(start <= idx){
        while(sum < n && end < idx){
            sum += plist[end];
            end++;
        }
        if(sum == n) cnt++; // 부분합이 더 클 경우
        sum -= plist[start];
        start++;
        //cout << sum << endl;
    }
    cout << cnt;

}