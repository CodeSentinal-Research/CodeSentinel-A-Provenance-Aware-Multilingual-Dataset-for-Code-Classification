def countSubarrays(nums):
    count = 0
    valid = 0
    for num in nums:
        if num == 0:
            count = 0
        else:
            count += 1
        valid += count
    return valid

def main():
    nums = list(map(int, input().split()))
    print(countSubarrays(nums))

if __name__ == "__main__":
    main()