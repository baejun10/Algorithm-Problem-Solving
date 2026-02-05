
q = int(input())
for _ in range(q):
    m = int(input())
    start = 366 # 6:06 국내선 첫차 시간(분)
    movcnt = m // 50
    dur = movcnt * 12 # 12분 단위로 반복 (이동4 + 정차2 + 이동4 + 정차2)
    end = start + dur # 출발 시간
    hour = end // 60
    minute = end % 60
    print(f"{hour:02d}:{minute:02d}")

