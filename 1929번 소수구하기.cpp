#include <stdio.h>

int arr[1000001]={0,};

int main() {

	int M=0, N=0;

	scanf("%d %d", &M, &N);
	for (int w = 2; w <= N; w++) {
		if (arr[w] == 1) {//체로 걸러진다면 돌아가기
			continue;
		}
		for (int e = 2; e * w <= N ; e++) {//w(소수)의 배수를 거르기 w는 제외
			arr[w * e] = 1;
		}
	}
	for (int q = M; q <= N; q++) {//M부터 N까지 소수 인지 확인
		if (arr[q] == 0 && q != 1) { //1은 소수 제외
			printf("%d\n", q);
		}
	}
}