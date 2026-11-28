def find_subarray(nums, k):
    n = len(nums)
    prefix_sum = [0] * (n + 1)
    for i in range(n):
        prefix_sum[i + 1] = prefix_sum[i] + nums[i]
    for start in range(n):
        for end in range(start + 2, n + 1):
            if k == 0:
                if prefix_sum[end] == prefix_sum[start]:
                    return True
            else:
                if prefix_sum[end] - prefix_sum[start] % k == 0:
                    return True
    return False

def main():
    nums = list(map(int, input().split()))
    k = int(input())
    print(find_subarray(nums, k))

if __name__ == "__main__":
    main()