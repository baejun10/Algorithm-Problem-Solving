import sys
input = sys.stdin.readline

n, d, k, c = map(int, input().split())

#belt = list(map(int, sys.stdin.read().split())) 이거 썼다가 메모리 초과 뜸. 줄로 안나누고 한번에 처리해서 복사 비용이 들어서 그런듯?
belt = [int(input()) for _ in range(n)]


# def get_kinds(sp, c): # n*k 번 반복하면 9*10^9번 연산이라 시간초과 뜰듯
#     global k
#     kind_set = set()
#     for i in range(k):
#         kind_set.add(belt[(i+sp) % n])
#     if c not in kind_set:
#         return len(kind_set) + 1
#     else:
#         return len(kind_set)

# max_kinds = 0
# for i in range(n):
#     max_kinds  = max(max_kinds, get_kinds(i, c))
# print(max_kinds)

# 초밥의 가짓수가 3000개로 적으므로 배열로 종류 카운팅 가능할듯
kinds = [0]*3002
max_kinds = 0
cnt = 0
num_kinds = 0

# 초기 k개 카운팅
for i in range(0, k):
    if kinds[belt[i%n]] == 0:
        num_kinds += 1
    kinds[belt[i%n]] += 1
   # 슬라이딩 윈도우 식으로 초밥 추가 및 범위 밖 초밥 제거 반복
for i in range(k, n+k):
    if kinds[belt[i%n]] == 0:
        num_kinds += 1
    kinds[belt[i%n]] += 1

    kinds[belt[i-k]] -= 1
    if kinds[belt[i-k]] == 0: # 마지막 남은 종류인경우
        num_kinds -= 1
    # 쿠폰 고려
    if kinds[c] == 0: # 쿠폰이 기존 초밥과 안겹치면 +1
        max_kinds = max(num_kinds+1, max_kinds)
    else:
        max_kinds = max(num_kinds, max_kinds)

print(max_kinds)
    


