def findUnsortedSubarray(nums):
    sorted_nums = sorted(nums)
    start = end = None

    for i in range(len(nums)):
        if nums[i] != sorted_nums[i]:
            if start is None:
                start = i
            end = i

    if start is None:
        return 0
    else:
        return end - start + 1

def main():
    N = int(input().strip())
    nums = list(map(int, input().strip().split()))
    print(findUnsortedSubarray(nums))

if __name__ == '__main__':
    main()