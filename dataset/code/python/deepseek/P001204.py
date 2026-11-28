def longestWiggle(n, arr):
    if n < 2:
        return n

    up = [0] * n
    down = [0] * n

    up[0] = down[0] = 1

    for i in range(1, n):
        if arr[i] > arr[i-1]:
            up[i] = down[i-1] + 1
            down[i] = down[i-1]
        elif arr[i] < arr[i-1]:
            down[i] = up[i-1] + 1
            up[i] = up[i-1]
        else:
            down[i] = up[i] = down[i-1]

    return max(max(up), down[-1])

def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(longestWiggle(n, arr))

if __name__ == "__main__":
    main()