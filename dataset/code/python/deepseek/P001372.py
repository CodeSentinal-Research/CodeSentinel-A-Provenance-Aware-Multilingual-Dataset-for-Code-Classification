def contains_duplicate(nums):
    nums_set = set()
    for num in nums:
        if num in nums_set:
            return True
        nums_set.add(num)
    return False

def main():
    N = int(input().strip())
    nums = list(map(int, input().strip().split()))
    print("YES" if contains_duplicate(nums) else "NO")

if __name__ == "__main__":
    main()