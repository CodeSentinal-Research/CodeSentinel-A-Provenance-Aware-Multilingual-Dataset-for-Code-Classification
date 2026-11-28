def count_prefixes(N, K, arr):
    count = 0
    prefix_sum = 0
    for num in arr:
        prefix_sum += num
        if prefix_sum % K == 0:
            count += 1
    return count

def main():
    N, K = map(int, input().split())
    arr = list(map(int, input().split()))
    print(count_prefixes(N, K, arr))

if __name__ == "__main__":
    main()