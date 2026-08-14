import sys

input = sys.stdin.readline

n, k = map(int, input().split())


temp = list(map(int, input().split()))

tsum = sum(temp[0:k])
maxsum = tsum

for i in range(1, n-k+1):
    tsum = tsum - temp[i-1] + temp[i+k-1]
    maxsum = max(tsum, maxsum)

print(maxsum)