# problem title : Print Any One Subsequence with Given Sum
# Solve the stated task using standard input and standard output.
import sys
def find_one_subseq(arr, idx, cur, cur_sum, target):
    if idx == len(arr):
        if cur_sum == target and cur:
            print(*cur)
            return True
        return False
    if find_one_subseq(arr, idx + 1, cur + [arr[idx]], cur_sum + arr[idx], target):
        return True
    if find_one_subseq(arr, idx + 1, cur, cur_sum, target):
        return True
    return False
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        target = int(tokens[1+n])
        if not find_one_subseq(nums, 0, [], 0, target):
            print(-1)
if __name__ == '__main__':
    main()
