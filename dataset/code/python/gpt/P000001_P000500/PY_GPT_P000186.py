# problem title : Maximum Length of Subarray with Positive Product
# A positive product needs an even number of negative values and no zero.
n = int(input()); a = list(map(int, input().split()))[:n]
positive = negative = best = 0
for x in a:
    if x == 0:
        positive = negative = 0
    elif x > 0:
        positive += 1; negative = negative + 1 if negative else 0
    else:
        positive, negative = (negative + 1 if negative else 0), positive + 1
    best = max(best, positive)
print(best)
