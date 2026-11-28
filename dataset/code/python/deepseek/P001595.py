def sum_between_two_positions(N, arr, L, R):
    return sum(arr[L:R+1])

N = int(input().strip())
arr = list(map(int, input().strip().split()))
L, R = map(int, input().strip().split())

print(sum_between_two_positions(N, arr, L, R))