from collections import deque
q = deque()
n = int(input())
for i in range(0, n):
    cmd, *args = input().split(' ')
    if cmd == 'c':
        print(len(q))
    elif cmd == 'i':
      q.append(args[0]) 
    elif cmd == 'o':
       if len(q) == 0:
        print("empty")
       else: print(q.popleft())
