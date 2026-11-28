# problem title : Find Second Smallest Element
# Track the two smallest distinct values without sorting the input.
n = int(input()); a = list(map(int, input().split()))[:n]
small = second = None
for x in a:
    if small is None or x < small:
        if x != small: second, small = small, x
    elif x != small and (second is None or x < second):
        second = x
print(second if second is not None else -1)
