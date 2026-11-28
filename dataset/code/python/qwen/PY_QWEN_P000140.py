m, n = map(int, input().split())
arr1 = list(map(int, input().split()))
arr2 = list(map(int, input().split()))
print(" ".join(map(str, list(set(arr1) | set(arr2)))))
