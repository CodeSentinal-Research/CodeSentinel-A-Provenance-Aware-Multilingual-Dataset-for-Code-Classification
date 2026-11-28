Here is the Python code for the problem:

def max_sum_after_negations(nums, k):
    nums.sort(reverse=True)

    for i in range(len(nums)):
        if nums[i] >= 0 and k > 0:
            nums[i] = -nums[i]
            k -= 1

    return sum(nums)

def main():
    N, K = map(int, input().split())
    nums = list(map(int, input().split()))

    print(max_sum_after_negations(nums, K))

if __name__ == "__main__":
    main()

In this code, we first sort the array in non-increasing order. Then, for each element in the sorted array, if it is positive and k > 0, we negate it and decrement k. This way, we ensure that the biggest possible number is negated first and it remains positive for k times. Finally, we sum all the elements in the array and return the sum.