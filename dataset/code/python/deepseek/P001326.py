def get_subsets(nums):
    subsets = [[]]
    for num in sorted(nums):
        if num not in subsets[-1]:
            subsets += [subset + [num] for subset in subsets]
    return subsets

def main():
    nums = list(map(int, input().split()))
    nums = nums[1:]
    subsets = get_subsets(nums)
    for subset in sorted(subsets):
        print(' '.join(map(str, subset)))

if __name__ == "__main__":
    main()