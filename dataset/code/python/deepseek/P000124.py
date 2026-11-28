def product_array(N, nums):
    prefix, suffix = [1]*N, [1]*N

    for i in range(N):
        if i > 0:
            prefix[i] = nums[i-1] * prefix[i-1]
    for i in range(N-1, -1, -1):
        if i < N-1:
            suffix[i] = nums[i+1] * suffix[i+1]

    for i in range(N):
        if i == 0:
            suffix[i] = suffix[i+1]
        elif i == N-1:
            prefix[i] = prefix[i-1]
        else:
            prefix[i] = prefix[i-1] * suffix[i+1]

    return prefix

def main():
    N = int(input().strip())
    nums = list(map(int, input().strip().split()))
    result = product_array(N, nums)
    print(' '.join(map(str, result)))

if __name__ == "__main__":
    main()

In this solution, we use the prefix and suffix array to store the product of numbers on either side of each number in the input array. The prefix array stores the product of numbers to the left of each number, and the suffix array stores the product of numbers to the right of each number. We calculate these two arrays in a single pass and then construct the final output array by multiplying the prefix and suffix arrays.