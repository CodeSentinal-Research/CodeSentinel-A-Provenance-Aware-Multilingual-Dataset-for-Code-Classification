def count_smaller_elements():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    res = [0] * N
    for i in range(N-1, -1, -1):
        for j in range(i+1, N):
            if arr[i] > arr[j]:
                res[i] += 1
    print(' '.join(map(str, res)))

if __name__ == "__main__":
    count_smaller_elements()