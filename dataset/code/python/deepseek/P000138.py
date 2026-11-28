def merge_arrays():
    M, N = map(int, input().split())
    array1 = sorted(map(int, input().split()))
    array2 = sorted(map(int, input().split()))
    i = 0
    j = 0
    result = []
    while i < M and j < N:
        if array1[i] < array2[j]:
            result.append(array1[i])
            i += 1
        else:
            result.append(array2[j])
            j += 1
    while i < M:
        result.append(array1[i])
        i += 1
    while j < N:
        result.append(array2[j])
        j += 1
    print(*result)


def main():
    merge_arrays()


if __name__ == "__main__":
    main()