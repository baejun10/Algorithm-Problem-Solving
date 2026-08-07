import sys

input = sys.stdin.readline

n = int(input())
diffArr = [0]*100005
for i in range(n):
    s, e, c = map(int, input().split())
    diffArr[s] += c
    diffArr[e+1] -= c

totalArr = [0]*100002
for i in range(1, 100001):
    totalArr[i] = diffArr[i] + totalArr[i-1]

q = int(input())
for i in range(q):
    query = int(input())
    print(totalArr[query])

