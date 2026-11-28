m, n = map(int, input().split())
arr1 = list(map(int, input().split()))
arr2 = list(map(int, input().split()))
order = {x: i for i, x in enumerate(arr2)}
arr1.sort(key=lambda x: (order.get(x, len(arr2)), x))
print(" ".join(map(str, arr1)))
