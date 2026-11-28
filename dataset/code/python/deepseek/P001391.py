def subarrays_with_sum_k(n, k, arr):
    from collections import defaultdict

    prefix_sum = defaultdict(int)
    prefix_sum[0] = 1  

    count = sum_ = 0
    for num in arr:
        sum_ += num
        if sum_ - k in prefix_sum:
            count += prefix_sum[sum_ - k]
        prefix_sum[sum_] += 1

    return count


def main():
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    print(subarrays_with_sum_k(n, k, arr))


if __name__ == "__main__":
    main()