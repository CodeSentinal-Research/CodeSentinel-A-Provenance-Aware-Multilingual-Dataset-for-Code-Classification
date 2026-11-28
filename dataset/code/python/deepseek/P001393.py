def find_continuous_subarray(N, K, arr):
    mod_arr = [0] * N
    for i in range(N):
        mod_arr[i] = arr[i] % K

    for i in range(N):
        for j in range(i + 2, N + 1):
            if sum(mod_arr[i:j]) % K == 0:
                return 'YES'

    return 'NO'

def main():
    N, K = map(int, input().split())
    arr = list(map(int, input().split()))

    print(find_continuous_subarray(N, K, arr))

if __name__ == "__main__":
    main()