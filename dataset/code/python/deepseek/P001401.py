Here is the Python code for your problem:

def max_subarray_sum(nums, k):
    prefix_sums = {0: -1}
    max_len = 0
    cur_sum = 0

    for i, num in enumerate(nums):
        cur_sum += num
        if cur_sum not in prefix_sums:
            prefix_sums[cur_sum] = i
        if cur_sum - k in prefix_sums:
            max_len = max(max_len, i - prefix_sums[cur_sum - k])

    return max_len

def main():
    N, K = map(int, input().split())
    nums = list(map(int, input().split()))
    print(max_subarray_sum(nums, K))

if __name__ == "__main__":
    main()

The main function takes the number of elements N and the target sum K, and reads the N numbers from the input. It then calls the `max_subarray_sum` function with these two values.