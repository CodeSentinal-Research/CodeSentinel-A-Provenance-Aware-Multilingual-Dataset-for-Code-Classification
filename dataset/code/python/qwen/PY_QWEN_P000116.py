n = int(input())
arr = list(map(int, input().split()))
expected = n * (n + 1) // 2
print(expected - sum(arr))
