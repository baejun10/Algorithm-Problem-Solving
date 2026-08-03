
s =  []

m = int(input())
raw = input().split(' ')

def ops(cmd, a, b):
    if cmd == '+':
        return a+b
    
    if cmd == '-' :
        return a-b
    if cmd == '/':
        return a//b
    if cmd == '*':
        return a*b
    
nums = "0123456789"
ans = 0
for i in raw:
    if i in nums:
        s.append(int(i))
    else:
        b = s.pop()
        a = s.pop()
        res = ops(i, a, b)
        s.append(res)
        
ans = s[0]
print(ans)

