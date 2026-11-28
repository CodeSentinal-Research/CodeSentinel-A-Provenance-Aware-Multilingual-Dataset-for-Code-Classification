def min_jumps(arr):
    n = len(arr)
    if n == 1:
        return 0
    if arr[0] == 0:
        return float('inf')
    
    jumps = [float('inf')] * n
    jumps[0] = 0

    for i in range(1, n):
        for j in range(i):
            if (i <= j + arr[j] and jumps[i] > jumps[j] + 1):
                jumps[i] = jumps[j] + 1
    return jumps[-1]


if __name__ == "__main__":
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(min_jumps(arr))