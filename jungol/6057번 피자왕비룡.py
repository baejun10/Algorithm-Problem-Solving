from collections import deque

p, n = map(int, input().split())

pizzas = []
for type in range(0, 52): #피자 종류별 큐를 따로 만들기
    pizzas.append(deque())

revenue = 0

for i in range (0, n):
    cmd, *args = map(int, input().split())

    if cmd == 0:
        pizzas[args[0]].append(args[1])
    elif cmd == 1:
        if len(pizzas[args[0]]) == 0: # 피자 없으면 스킵
            # print(f"{args[0]}번 피자 없음")
            continue
        else:
            money = pizzas[args[0]].popleft()
            revenue += money
            # print(f"{args[0]}번 피자:{money}, 총 수익: {revenue}")

print(revenue)