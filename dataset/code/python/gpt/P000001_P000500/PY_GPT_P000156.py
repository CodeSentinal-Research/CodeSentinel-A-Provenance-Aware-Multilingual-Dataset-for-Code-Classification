# problem title : Maximum Consecutive Zeros
# The same run technique applies to zeroes.
n = int(input()); a = list(map(int, input().split()))[:n]
streak = longest = 0
for bit in a:
    if bit == 0: streak += 1; longest = max(longest, streak)
    else: streak = 0
print(longest)
