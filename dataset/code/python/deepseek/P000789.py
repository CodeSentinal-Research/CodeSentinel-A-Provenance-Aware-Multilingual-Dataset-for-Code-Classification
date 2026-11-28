def subarraySum(nums, k):
    count = 0
    for i in range(len(nums)):
        sum = 0
        for j in range(i, len(nums)):
            sum += nums[j]
            if sum == k:
                count += 1
    return count

def main():
    n = int(input().strip())
    nums = list(map(int, input().strip().split(' ')))
    k = int(input().strip())
    print(subarraySum(nums, k))

if __name__ == "__main__":
    main()