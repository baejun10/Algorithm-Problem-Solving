import sys

input = sys.stdin.readline

n, q = map(int, input().split())
logs = []

for i in range(1, n + 1):
    x1, x2, y = map(int, input().split())
    # 원래 통나무 번호(i)를 함께 저장
    logs.append((x1, x2, y, i))

# x1 기준 정렬
logs.sort(key=lambda x: x[0])

loggroup = [0] * (n + 1)

# 첫 번째 통나무 초기화
ax1, ax2, ay, idx = logs[0]
maxx = ax2
groupnum = 1
loggroup[idx] = groupnum

for i in range(1, n):
    bx1, bx2, by, idx = logs[i]
    if bx1 <= maxx:
        loggroup[idx] = groupnum
        maxx = max(maxx, bx2)
    else:
        groupnum += 1
        loggroup[idx] = groupnum
        maxx = bx2  # 새 그룹이므로 현재 통나무 끝점으로 갱신


def query(a, b):
    if loggroup[a] == loggroup[b]:
        print(1)
    else:
        print(0)


for _ in range(q):
    a, b = map(int, input().split())
    query(a, b)
