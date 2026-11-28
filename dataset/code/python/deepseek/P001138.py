def coin_change(n, amount):
    ways = [0] * (amount + 1)
    ways[0] = 1

    for i in range(n):
        for j in range(amount + 1):
            for k in range(coin[i], amount + 1):
                ways[k] += ways[k - coin[i]]
    return ways[amount]

n, amount = map(int, input().split())
coin = list(map(int, input().split()))
print(coin_change(n, amount))