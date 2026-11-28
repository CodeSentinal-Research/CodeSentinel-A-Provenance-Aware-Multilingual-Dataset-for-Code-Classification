# problem title : Print All Subsequences with Given Sum
# Solve the stated task using standard input and standard output.
import sys
def find_all_subseq(arr, idx, cur, cur_sum, target, res):
    if idx == len(arr):
        if cur_sum == target and cur:
            res.append(list(cur))
        return
    find_all_subseq(arr, idx + 1, cur, cur_sum, target, res)
    find_all_subseq(arr, idx + 1, cur + [arr[idx]], cur_sum + arr[idx], target, res)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        target = int(tokens[1+n])
        res = []
        find_all_subseq(nums, 0, [], 0, target, res)
        res.sort()
        for seq in res:
            print(*seq)
if __name__ == '__main__':
    main()
