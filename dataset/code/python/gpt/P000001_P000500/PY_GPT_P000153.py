# problem title : Rearrange Positive and Negative Numbers
# Separate signs, then alternate while both groups have values.
n = int(input()); a = list(map(int, input().split()))[:n]
pos = [x for x in a if x >= 0]; neg = [x for x in a if x < 0]
out = []
while pos or neg:
    if pos: out.append(pos.pop(0))
    if neg: out.append(neg.pop(0))
print(*out)
