# problem title : Check if Array is Sorted Ascending
# Every adjacent pair must be nondecreasing for ascending order.
n = int(input()); a = list(map(int, input().split()))[:n]
ok = all(a[i] <= a[i + 1] for i in range(n - 1))
print("Sorted" if ok else "Not Sorted")
