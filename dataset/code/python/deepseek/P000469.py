def search_range(nums, target):
    low = high = -1

    for i in range(len(nums)):
        if nums[i] == target:
            low = i
            break

    if low == -1:
        return [-1, -1]

    for i in range(len(nums) - 1, -1, -1):
        if nums[i] == target:
            high = i
            break

    return [low, high]

def main():
    N = int(input().strip())
    nums = list(map(int, input().strip().split()))
    target = int(input().strip())
    low, high = search_range(nums, target)
    print(low, high)

if __name__ == "__main__":
    main()