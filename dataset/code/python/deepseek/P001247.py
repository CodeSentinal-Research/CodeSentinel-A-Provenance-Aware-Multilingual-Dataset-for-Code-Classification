def max_indices():
    N = int(input().strip())
    arr1 = list(map(int, input().strip().split()))
    arr2 = list(map(int, input().strip().split()))

    arr1.sort()
    arr2.sort(reverse=True)

    max_ind = [0] * N
    for i in range(N):
        if arr1[i] > arr2[i]:
            max_ind[i] = 1

    print(' '.join(map(str, max_ind)))


if __name__ == "__main__":
    max_indices()