import sys
def subsets_with_dup(nums, idx, cur):
    print(*cur)
    for i in range(idx, len(nums)):
        if i > idx and nums[i] == nums[i - 1]: continue
        subsets_with_dup(nums, i + 1, cur + [nums[i]])
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = sorted(list(map(int, tokens[1:1+n])))
        subsets_with_dup(nums, 0, [])
if __name__ == '__main__':
    main()