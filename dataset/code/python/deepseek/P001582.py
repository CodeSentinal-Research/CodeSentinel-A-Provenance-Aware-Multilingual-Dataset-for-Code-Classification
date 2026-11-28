def max_ones(N, K, arr):
    zero_count = 0
    ones_count = 0
    max_length = 0

    start = 0
    end = 0

    while end < N:
        if arr[end] == 0:
            zero_count += 1
            if zero_count == K:
                while arr[start] == 0:
                    start += 1
                zero_count -= 1
        else:
            while arr[end] == 1 and end < N - 1:
                end += 1
            ones_count += 1
            if ones_count > max_length:
                max_length = ones_count
            if arr[end] == 0:
                while arr[end] == 0 and end < N - 1:
                    end += 1
                ones_count = 0
        end += 1

    return max_length

N = int(input().split()[0])
K = int(input().split()[1])
arr = list(map(int, input().split()))

print(max_ones(N, K, arr))