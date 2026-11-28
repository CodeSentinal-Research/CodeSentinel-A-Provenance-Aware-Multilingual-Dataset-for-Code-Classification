# problem title : Longest Subarray with Equal 0s and 1s
# Treat 0 as -1; equal prefix sums then represent equal counts of 0 and 1.
n = int(input()); a = list(map(int, input().split()))[:n]
first = {0: 0}; balance = best = 0
for i, bit in enumerate(a, 1):
    balance += 1 if bit else -1
    if balance in first: best = max(best, i - first[balance])
    else: first[balance] = i
print(best)
