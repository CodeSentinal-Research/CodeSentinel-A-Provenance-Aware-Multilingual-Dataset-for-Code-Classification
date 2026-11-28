def searchInsert(nums, target):
    for i in range(len(nums)):
        if nums[i] >= target:
            return i
    return len(nums)

def main():
    N = int(input().strip())
    target = int(input().strip())
    nums = list(map(int, input().strip().split()))
    insert_index = searchInsert(nums, target)
    print(insert_index)

if __name__ == "__main__":
    main()