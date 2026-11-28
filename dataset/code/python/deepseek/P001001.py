def findKthLargest(nums, k):
    nums.sort(reverse=True)
    return nums[k-1]

def main():
    nums = list(map(int, input().split()))
    k = int(input().split()[1])
    print(findKthLargest(nums, k))

if __name__ == "__main__":
    main()