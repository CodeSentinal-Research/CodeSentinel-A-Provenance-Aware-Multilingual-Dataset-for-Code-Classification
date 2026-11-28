def find_first_odd(N, arr):
    for i in range(N):
        if arr[i] % 2 != 0:
            return i
    return -1

N = int(input())
arr = list(map(int, input().split()))
print(find_first_odd(N, arr))