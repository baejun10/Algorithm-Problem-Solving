import sys


def solve():
    lines = sys.stdin.read().splitlines()
    for line in lines:
        if not line or line.strip() == "0":
            break

        A_str, S, B_str = line.split()
        A, B = int(A_str), int(B_str)

        # 1. A진법 문자열 S를 10진수 정수로 '딸깍' 변환
        decimal_num = int(S, A)

        # 2. 10진수를 B진법으로 변환 (0 예외처리)
        if decimal_num == 0:
            print(0)
            continue

        words = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        result = []
        while decimal_num > 0:
            result.append(words[decimal_num % B])
            decimal_num //= B

        print("".join(reversed(result)))


solve()
