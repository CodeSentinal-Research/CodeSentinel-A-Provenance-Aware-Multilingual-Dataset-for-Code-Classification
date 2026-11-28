# problem title : Find the First Repeating Element
# The first value whose second occurrence is encountered is the answer.
n = int(input()); a = list(map(int, input().split()))[:n]
seen = set(); answer = -1
for x in a:
    if x in seen: answer = x; break
    seen.add(x)
print(answer)
