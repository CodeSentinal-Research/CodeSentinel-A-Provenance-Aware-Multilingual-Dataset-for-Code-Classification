def intersect_twodimensional_arrays():
    N, M = map(int, input().split())
    arr1 = list(map(int, input().split()))
    arr2 = list(map(int, input().split()))

    i, j, k = 0, 0, 0

    while i < N and j < M:
        if arr1[i] < arr2[j]:
            i += 1
        elif arr1[i] > arr2[j]:
            j += 1
        else:
            print(arr1[i], end=' ')
            i += 1
            j += 1

intersect_twodimensional_arrays()