import sys
def min_subarray(nums, p):
    target = sum(nums) % p
    if target == 0: return 0
    seen = {0: -1}
    cur = 0
    min_len = len(nums)
    for i, x in enumerate(nums):
        cur = (cur + x) % p
        needed = (cur - target + p) % p
        if needed in seen:
            min_len = min(min_len, i - seen[needed])
        seen[cur] = i
    return min_len if min_len < len(nums) else -1
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        p = int(tokens[1+n])
        print(min_subarray(nums, p))
if __name__ == '__main__':
    main()