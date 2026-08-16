import sys

input = sys.stdin.readline

n, m = map(int, input().split())

cstate = [i for i in range(200002)] # 정점과 같은 그룹 표시하는 배열



def find(u):
    # 루트 노드 발견
    if cstate[u] == u:
        return u
    else:
        cstate[u] = find(cstate[u]) #경로 압축
        return cstate[u]

for i in range(m):
    u, v = map(int, input().split())

    pu = find(u)
    pv = find(v)
        
    
    if pu > pv: pu, pv = pv, pu # 작은 숫자로 루트 통일
        
    if pu == pv:
        continue
    # print(f"{u}, {v} connect to {pu}")
    cstate[pv] = pu # 작은 번호로 통일

# 서로소 집합의 개수
disjoint_set = set()
# print(cstate[1:n+1])
for i in range(1, n+1):
    disjoint_set.add(find(i))
# print(disjoint_set) # 0 제외하고 카운트 해야함.
print(len(disjoint_set)-1)

    



