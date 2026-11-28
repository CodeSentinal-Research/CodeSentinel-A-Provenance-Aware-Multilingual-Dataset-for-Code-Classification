# problem title : Maximum Consecutive Ones
# Track the current and maximum run of ones.
n = int(input()); a = list(map(int, input().split()))[:n]
run = best = 0
for x in a:
    run = run + 1 if x == 1 else 0
    best = max(best, run)
print(best)
