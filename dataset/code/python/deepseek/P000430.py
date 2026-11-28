def linear_search_from_end():
    N = int(input().strip())
    target = int(input().strip())
    arr = [int(x) for x in input().strip().split()]

    for i in range(N-1, -1, -1):
        if arr[i] == target:
            return i

    return -1

print(linear_search_from_end())