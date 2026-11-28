# problem title : Two Sum
# Store previous values so each complement can be found in constant average time.
n, target = map(int, input().split()); a = list(map(int, input().split()))[:n]
seen = {}
answer = (-1, -1)
for i, x in enumerate(a):
    need = target - x
    if need in seen:
        answer = (seen[need], i); break
    if x not in seen: seen[x] = i
print(*answer)
