def checkIfExist(nums):
    nums_set = set(nums)
    for num in nums:
        if num*2 in nums_set:
            return 'YES'
    return 'NO'

def main():
    N = int(input().strip())
    nums = list(map(int, input().strip().split()))[:N]
    print(checkIfExist(nums))

if __name__ == '__main__':
    main()