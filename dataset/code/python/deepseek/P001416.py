def find_longest_harmonious_subsequence(nums):
    nums.sort()
    max_len = 0
    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
            if nums[j] - nums[i] == 1:
                max_len = max(max_len, j - i + 1)
    return max_len

def main():
    N = int(input().strip())
    nums = list(map(int, input().strip().split()))
    print(find_longest_harmonious_subsequence(nums))

if __name__ == "__main__":
    main()