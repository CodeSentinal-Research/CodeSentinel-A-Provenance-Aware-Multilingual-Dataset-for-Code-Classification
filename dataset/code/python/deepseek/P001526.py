def find_minimum_length_subarray():
    N, Target = map(int, input().split())
    arr = list(map(int, input().split()))

    min_length = float('inf')
    sum_arr = sum(arr[:N])

    if sum_arr >= Target:
        min_length = 1

    else:
        for i in range(N, 0, -1):
            sum_arr -= arr[i-1]
            if sum_arr >= Target:
                min_length = min(min_length, i)
                break

    print(min_length if min_length != float('inf') else 0)


find_minimum_length_subarray()