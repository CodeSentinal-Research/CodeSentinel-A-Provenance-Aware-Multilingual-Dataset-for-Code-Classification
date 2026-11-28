def min_passes(n, nums):
    nums.sort()
    i = 0
    passes = 0
    while i < n:
        max_num = nums[i]
        while i < n and nums[i] <= max_num:
            i += 1
        passes += 1
    return passes

def main():
    n = int(input())
    nums = list(map(int, input().split()))
    print(min_passes(n, nums))

if __name__ == "__main__":
    main()