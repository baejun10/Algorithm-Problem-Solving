import sys

input = sys.stdin.readline

n, m = map(int, input().split())

cstate = [0] * 200002

def swap(u, v):
    tmp = u
    u = v
    v = tmp

def find(u):
    if cstate[u] == u:
        return u
    else:
        cstate[u] = find(cstate[u]) #경로 압축
        return cstate[u]

for i in range(m):
    u, v = map(int, input().split())

    pu = find(u)
    pv = find(v)
    if pu == 0: # 초기 숫자 부여
        pu = u

    if pv == 0:
        pv = v
        
    
    if pu > pv: pu, pv = pv, pu
        
    if pu == pv:
        break
    cstate[pu] = pu
    cstate[pv] = pu # 작은 번호로 통일

# 서로소 집합의 개수
disjoint_set = set()

for i in range(1, n+1):
    disjoint_set.add(cstate[n])
print(disjoint_set) # 0 제외하고 카운트 해야함.
print(len(disjoint_set)-1)

    



