def merge_sorted_arrays():
    N, M = map(int, input().split())
    array1 = sorted(map(int, input().split()))
    array2 = sorted(map(int, input().split()))
    result = array1 + array2
    result.sort()
    print(*result)

merge_sorted_arrays()