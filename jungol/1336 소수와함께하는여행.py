from collections import deque

s, e = map(int, input().split())

primes = []

MAX = 10000
is_prime_table = [True] * MAX
is_prime_table[0] = is_prime_table[1] = False
# 소수 구하기
for i in range(2, int(MAX**0.5) + 1):
    if is_prime_table[i]:
        for j in range(i * i, MAX, i):
            is_prime_table[j] = False


bus_stops = [i for i in range(1000,10000) if is_prime_table[i]]

def is_conn(a, b):
    same_cnt = 0
    for i in [1000, 100, 10, 1]:
        if a//i == b//i:
            same_cnt += 1
        a -= i * (a//i)
        b -= i * (b//i)
    if same_cnt >= 3:
        return True
    return False

conn = []

q = deque()
q.append(s)
depth = 0
#bfs
print(q)
while len(q) != 0:
    
    cur = q.popleft()
    for stop in bus_stops:
        if cur == e:
            break
        if is_conn(cur, stop):
            q.append(stop)
    depth += 1
print(depth)


