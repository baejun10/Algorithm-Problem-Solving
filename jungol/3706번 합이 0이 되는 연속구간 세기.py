import sys
from collections import Counter


def solve():
    input = sys.stdin.read
    data = input().split()

    if not data:
        return

    n = int(data[0])
    arr = list(map(int, data[1:]))

    # 누적 합 빈도수 저장용 Counter
    sum_counts = Counter()

    # S[0] = 0 이 1번 등장했다고 초기화 (원소 자체 또는 첫 부분 합이 0인 경우 대비)
    sum_counts[0] = 1

    current_sum = 0
    ans = 0

    for num in arr:
        current_sum += num  # 현재 위치까지의 누적 합 계산

        # 1. 현재 누적 합(current_sum)과 같은 값이 이전에 등장했던 횟수만큼 정답에 더함
        ans += sum_counts[current_sum]

        # 2. 현재 누적 합의 등장 횟수를 1 증가시킴
        sum_counts[current_sum] += 1

    print(ans)


if __name__ == "__main__":
    solve()
