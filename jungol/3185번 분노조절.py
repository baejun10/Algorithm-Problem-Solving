import sys

input = sys.stdin.readline


def main():
    n = int(input())
    k = int(input())

    bread = [int(input()) for _ in range(n)]

    # 1. 오름차순 정렬
    bread.sort()
    # 논리는 정렬했을때 윈도우로 선택하면 전체 차이가 작을수밖에 없다.
    # 2. 첫 윈도우(0 ~ k-1)의 합 및 분노도 초기화
    window_sum = 0
    current_rage = 0

    for i in range(k):
        window_sum += bread[i]
        # (2*i + 1 - k) 공식을 사용해 첫 윈도우 분노도 계산
        #$k$개 원소가 있을 때 $i$번째 원소(0-indexed)의 입장을 머릿속으로 단순하게 따져봅니다.
        # 내 앞에 있는 $i$개 원소보다는 내가 크거나 같으니까 $\rightarrow$ $+i$번 더해짐
        # 내 뒤에 있는 $(k - 1 - i)$개 원소보다는 내가 작거나 같으니까 $\rightarrow$ $-(k - 1 - i)$번 빼어짐
        # 따라서 내 계수는 $i - (k - 1 - i) = \mathbf{2i + 1 - k}$
        current_rage += (2 * i + 1 - k) * bread[i]

    min_rage = current_rage

    # 3. O(1) 슬라이딩 윈도우 탐색 (i: 제거되는 원소의 인덱스)
    for i in range(n - k):
        # O(1) 점화식 적용
        current_rage = (
            current_rage
            - 2 * (window_sum - bread[i])
            + (k - 1) * (bread[i] + bread[i + k])
        )

        # 윈도우 합 갱신 (A[i] 제외, A[i+k] 추가)
        window_sum += bread[i + k] - bread[i]

        # 최소 분노도 갱신
        if current_rage < min_rage:
            min_rage = current_rage

    print(min_rage)


if __name__ == "__main__":
    main()