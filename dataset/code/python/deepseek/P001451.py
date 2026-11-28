def countPairs(nums, k):
    count = 0
    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
            if nums[i] == nums[j] and nums[i] + nums[j] == k:
                count += 1
    return count

def main():
    N, K = map(int, input().split())
    nums = list(map(int, input().split()))
    print(countPairs(nums, K))

if __name__ == "__main__":
    main()