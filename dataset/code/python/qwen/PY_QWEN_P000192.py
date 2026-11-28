n = int(input())
arr = list(map(int, input().split()))
neg = [x for x in arr if x < 0]
pos = [x for x in arr if x >= 0]
print(" ".join(map(str, neg + pos)))
