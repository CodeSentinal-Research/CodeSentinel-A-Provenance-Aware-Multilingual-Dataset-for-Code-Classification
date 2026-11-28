def minimize_max_pair_sum(n, arr):
    arr.sort()
    pair_sum = 0
    for i in range(n//2):
        pair_sum += arr[i] + arr[n-1-i]
    return pair_sum

def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(minimize_max_pair_sum(n, arr))

if __name__ == "__main__":
    main()