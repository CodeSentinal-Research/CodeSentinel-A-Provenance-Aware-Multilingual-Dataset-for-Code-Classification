def count_good_pairs(nums):
    pair_counts = {}
    good_pairs = 0
    for num in nums:
        pair_counts[num] = pair_counts.get(num, 0) + 1
    for count in pair_counts.values():
        good_pairs += count * (count - 1) // 2
    return good_pairs

def main():
    N = int(input().strip())
    nums = list(map(int, input().strip().split()))
    print(count_good_pairs(nums))

if __name__ == "__main__":
    main()