# problem title : Remove Duplicates from Sorted Array
# The array is sorted, so only a write pointer is needed.
n = int(input()); a = list(map(int, input().split()))[:n]
if n:
    write = 1
    for read in range(1, n):
        if a[read] != a[write - 1]:
            a[write] = a[read]; write += 1
    print(write)
else:
    print(0)
