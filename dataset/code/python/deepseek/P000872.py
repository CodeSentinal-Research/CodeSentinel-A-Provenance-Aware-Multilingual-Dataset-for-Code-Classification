def findMaxXOR(nums):
    max_xor = 0
    for i in range(32):
        mask = 1 << i
        set_ = set()
        for num in nums:
            if num & mask:
                set_.add(num)
        for x in set_:
            if (max_xor | mask) ^ x in set_:
                max_xor = x
    return max_xor

def main():
    n = int(input())
    nums = list(map(int, input().split()))
    print(findMaxXOR(nums))

if __name__ == "__main__":
    main()