import sys

input = sys.stdin.readline

n = int(input())

chess = [['.' for _ in range (n)] for _ in range(n)]
for i in range(n):
    line = input()
    for j in range(n):
        chess[i][j] = line[j]

# print(chess)

cnt = 0
# '#'는 장애물
# n개 이므로 i, j 가 모두 겹치지 않아야한다.
usecol = [0]*n
# 행을 반복하면서 고유한 열을 선택하는 경우의 수를 구해야함.
def dfs(row):
    global usecol
    global cnt
    if row == n:
        cnt += 1
        return
    for j in range(n):
        if usecol[j] == 0 and chess[row][j] != '#':
            usecol[j] = 1
            dfs(row+1)
            usecol[j] = 0 # 다음 케이스 탐색을 위해 다시 해제

dfs(0)
print(cnt)

