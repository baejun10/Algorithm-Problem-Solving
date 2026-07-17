n = int(input())

num_list = list(map(int, input().split()))

def gcd(a, b):
    if a < b:
        tmp = a
        a = b
        b = tmp
    while b != 0:
        tmp = a
        a = b
        b = tmp % b
    return a

def lcm(a, b):
    return (a * b) // gcd(a, b)

last_gcd = num_list[0]
last_lcm = num_list[0]
for i in range(1, n):
    last_gcd = gcd(last_gcd, num_list[i])
    last_lcm = lcm(last_lcm, num_list[i])

print(f"{last_gcd} {last_lcm}")