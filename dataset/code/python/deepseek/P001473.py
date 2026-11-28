def threeSumClosest(nums, target):
    nums.sort()
    diff = float('inf')
    for i in range(len(nums)):
        lo = i + 1
        hi = len(nums) - 1
        while lo < hi:
            sum = nums[i] + nums[lo] + nums[hi]
            if abs(target - sum) < abs(diff):
                diff = target - sum
            if sum < target:
                lo += 1
            else:
                hi -= 1
        if diff == 0:
            break
    return target - diff

def main():
    nums = list(map(int, input().split()))[1:]
    target = int(input().split()[0])
    print(threeSumClosest(nums, target))

if __name__ == "__main__":
    main()