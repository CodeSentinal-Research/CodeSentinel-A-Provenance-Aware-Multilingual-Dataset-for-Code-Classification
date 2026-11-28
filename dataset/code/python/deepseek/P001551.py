Here is a Python solution using two-pointer technique:

def longestSubarray(nums, k):
    n = len(nums)
    left, right = 0, 0
    cur_sum = 0
    max_len = 0

    while right < n:
        cur_sum += nums[right]

        while cur_sum > k:
            cur_sum -= nums[left]
            left += 1

        if right - left + 1 > max_len:
            max_len = right - left + 1

        right += 1

    return max_len


def main():
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    print(longestSubarray(nums, k))


if __name__ == "__main__":
    main()

This code first reads the input values for N and K, then reads the array A of N integers. The `longestSubarray` function then calls the two-pointer technique to find the longest subarray with sum less than or equal to K. The result is printed to the console.