n = int(input())
arr = list(map(int, input().split()))
even = [x for x in arr if x % 2 == 0]
odd = [x for x in arr if x % 2 != 0]
print(" ".join(map(str, even + odd)))
