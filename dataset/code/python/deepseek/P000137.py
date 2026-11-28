def find_duplicate(nums):
    nums.sort()
    for i in range(len(nums) - 1):
        if nums[i] == nums[i + 1]:
            return nums[i]
    return -1

def main():
    N = int(input().strip())
    nums = list(map(int, input().strip().split()))
    print(find_duplicate(nums))

if __name__ == "__main__":
    main()