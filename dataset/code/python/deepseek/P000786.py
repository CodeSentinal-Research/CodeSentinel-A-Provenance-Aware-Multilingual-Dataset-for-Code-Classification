Here is the Python code for the problem:

def left_right_sum_diff(nums):
    n = len(nums)
    left, right = [0]*n, [0]*n
    left[0] = nums[0]
    right[n-1] = nums[n-1]
    for i in range(1, n):
        left[i] = left[i-1] + nums[i]
    for i in range(n-2, -1, -1):
        right[i] = right[i+1] + nums[i]
    for i in range(n):
        nums[i] = abs(left[i]-right[i])
    return nums

def main():
    nums = list(map(int, input().split()))
    print(' '.join(map(str, left_right_sum_diff(nums))))

if __name__ == "__main__":
    main()

In this code, we first calculate the left and right sums of the array. Then, we calculate the absolute difference between the left sum and right sum for each element in the array. The resulting array is the one we wanted.