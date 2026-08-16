import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())

# 모든 노드에 대한 진입차수는 0으로 초기화
indegree = [0] * (n + 1)
# 각 노드에 연결된 간선 정보를 담기 위한 연결 리스트
graph = [[] for _ in range(n + 1)]

for i in range(n):
    seq = list(map(int, input().split()))
    for i in range(1, len(seq)-1):
        graph[seq[i]].append(seq[i+1]) 
        indegree[seq[i+1]] += 1
# print(graph)
# print(indegree)
def topology_sort():
    q = deque()
    result = []

    for i in range(1, n+1):
        if indegree[i] == 0: # 진입차수 0인거 큐에 삽입
            q.append(i)

    while q:
        # print(q)
        now = q.popleft()
        result.append(now) # 해당 시작 노드 정렬 결과에 추가

        for g in graph[now]: # 연결된 노드에 진입차수 빼기
            indegree[g] -= 1
            if indegree[g] == 0:
                q.append(g)
    return result

res = topology_sort()
if len(res) == n:
    for i in res:
        print(i)
else:
    print(0)
