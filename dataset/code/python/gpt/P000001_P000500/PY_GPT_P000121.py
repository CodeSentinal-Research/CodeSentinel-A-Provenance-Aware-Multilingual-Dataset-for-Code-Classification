# problem title : Find Majority Element
# Boyer-Moore finds a possible majority candidate in linear time.
n = int(input()); a = list(map(int, input().split()))[:n]
candidate = count = 0
for x in a:
    if count == 0: candidate = x
    count += 1 if x == candidate else -1
print(candidate if a.count(candidate) > n // 2 else -1)
