# problem title : Leaders in an Array
# Scan from the right; a leader is greater than every value seen after it.
n = int(input()); a = list(map(int, input().split()))[:n]
leaders = []; right_max = float('-inf')
for x in reversed(a):
    if x > right_max:
        leaders.append(x); right_max = x
print(*reversed(leaders))
