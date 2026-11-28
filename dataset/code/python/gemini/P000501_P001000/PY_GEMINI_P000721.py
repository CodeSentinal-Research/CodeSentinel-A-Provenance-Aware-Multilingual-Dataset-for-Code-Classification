import sys
def find_subseq(nums, idx, cur, res):
    if len(cur) >= 2:
        res.add(tuple(cur))
    for i in range(idx, len(nums)):
        if not cur or nums[i] >= cur[-1]:
            find_subseq(nums, i + 1, cur + [nums[i]], res)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        res = set()
        find_subseq(nums, 0, [], res)
        for seq in sorted(res):
            print(*seq)
if __name__ == '__main__':
    main()