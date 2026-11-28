def smallest_missing_number(nums):
    nums = set(nums)
    i = 1
    while i in nums:
        i += 1
    return i

def main():
    n = int(input())
    nums = list(map(int, input().split()))
    print(smallest_missing_number(nums))

if __name__ == "__main__":
    main()