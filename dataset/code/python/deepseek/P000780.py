def prefix_sum(nums):
    for i in range(1, len(nums)):
        nums[i] += nums[i - 1]
    return nums

def main():
    n = int(input().strip())
    nums = list(map(int, input().strip().split()))
    print(prefix_sum(nums))

if __name__ == "__main__":
    main()