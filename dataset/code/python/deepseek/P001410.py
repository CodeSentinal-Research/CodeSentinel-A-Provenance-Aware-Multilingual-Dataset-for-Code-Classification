def countBadPairs(nums):
    pair_counts = {}
    for i, num in enumerate(nums):
        pair_counts[num - i] = pair_counts.get(num - i, 0) + 1

    bad_pairs = 0
    for count in pair_counts.values():
        bad_pairs += count - 1

    return bad_pairs

def main():
    N = int(input().strip())
    nums = list(map(int, input().strip().split()))
    print(countBadPairs(nums))

if __name__ == '__main__':
    main()