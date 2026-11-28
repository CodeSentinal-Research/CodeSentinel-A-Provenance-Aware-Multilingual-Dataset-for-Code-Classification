Here is the Python code:

def countSubarrays(nums, goal):
    cnt = 0
    prefix = 0
    for num in nums:
        prefix += num
        while prefix > goal:
            prefix -= nums[cnt]
            cnt += 1
        if prefix == goal:
            len_subarray = cnt - 1 if cnt > 0 else 0
            cnt += (len_subarray if len_subarray > 0 else 0)
    return cnt

And here is the main function:

def main():
    nums = list(map(int, input("Enter binary array nums separated by space: ").strip().split()))
    goal = int(input("Enter integer goal: "))
    print("Number of valid subarrays: ", countSubarrays(nums, goal))

if __name__ == "__main__":
    main()

In this code, the prefix sum is used to count the number of subarrays with sum equal to the goal. For each number in the array, we add it to the prefix sum. If the prefix sum exceeds the goal, we subtract the last number and continue. If the prefix sum equals the goal, we increment the count of the number of subarrays.

Please note, for large inputs, this code could be slow because it traverses the array twice. A more efficient approach would be to use two pointers and a prefix sum array. This code can be further optimized for large inputs.