n = int(input())
arr = list(map(int, input().split()))
even = sum(1 for x in arr if x % 2 == 0)
odd = n - even
print(even, odd)
