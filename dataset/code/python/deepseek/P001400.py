def find_diff(N, arr1, M, arr2):
    arr1 = set(arr1)
    arr2 = set(arr2)

    arr1_only = arr1 - arr2
    arr2_only = arr2 - arr1

    print(' '.join(sorted(list(arr1_only))))
    print(' '.join(sorted(list(arr2_only))))


if __name__ == '__main__':
    N, M = map(int, input().split())
    arr1 = list(map(int, input().split()))
    arr2 = list(map(int, input().split()))
    find_diff(N, arr1, M, arr2)