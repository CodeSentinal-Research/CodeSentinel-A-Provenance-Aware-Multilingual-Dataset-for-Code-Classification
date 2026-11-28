# problem title : Find Second Largest Element
# Keep the two largest distinct values while scanning the array.
n = int(input()); a = list(map(int, input().split()))[:n]
first = second = None
for x in a:
    if first is None or x > first:
        if x != first: second, first = first, x
    elif x != first and (second is None or x > second):
        second = x
print(second if second is not None else -1)
