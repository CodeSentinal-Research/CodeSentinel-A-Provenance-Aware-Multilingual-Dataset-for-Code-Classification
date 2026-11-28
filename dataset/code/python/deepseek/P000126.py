Here is the Python code for the problem:

def threeSumClosest(nums, target):
    nums.sort()
    diff = float('inf')
    for i in range(len(nums)):
        left, right = i + 1, len(nums) - 1
        while left < right:
            sum = nums[i] + nums[left] + nums[right]
            if abs(target - sum) < abs(diff):
                diff = target - sum
            if sum < target:
                left += 1
            else:
                right -= 1
        if diff == 0:
            return target
    return target - diff


def main():
    nums = list(map(int, input().split()))
    target = int(input())
    print(threeSumClosest(nums, target))


if __name__ == '__main__':
    main()

In this code, we first sort the list of numbers. Then, for each number, we use two pointers to find a pair of numbers that sum to the remaining part of the target sum. If the current sum is closer to the target than the previous closest sum, we update the closest sum. If the sum is smaller than the target, we increment the left pointer; otherwise, we decrement the right pointer. This process continues until the left pointer and right pointer meet. If the closest sum is 0 at the beginning, we return the target as it is the best sum we can get.