def merge_sorted_arrays():
    N = int(input().strip())
    array1 = list(map(int, input().strip().split()))
    M = int(input().strip())
    array2 = list(map(int, input().strip().split()))

    i = 0
    j = 0

    while i < N and j < M:
        if array1[i] < array2[j]:
            print(array1[i], end=' ')
            i += 1
        else:
            print(array2[j], end=' ')
            j += 1

    while i < N:
        print(array1[i], end=' ')
        i += 1

    while j < M:
        print(array2[j], end=' ')
        j += 1


merge_sorted_arrays()