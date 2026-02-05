n = int(input())


for _ in range(n):
    kinds = int(input())
    coins = list(map(int, input().split()))
    amount = int(input())

    dp = [0] * (amount + 1)
    dp[0] = 1


    for c in coins:
        for x in range(c, amount + 1):
            dp[x] += dp[x - c]

    print(dp[amount])
    
