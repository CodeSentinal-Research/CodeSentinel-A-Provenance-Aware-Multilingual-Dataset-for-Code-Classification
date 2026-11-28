import sys
def count_subseq_sum(arr, idx, cur_sum, target):
    if idx == len(arr):
        return 1 if cur_sum == target else 0
    return count_subseq_sum(arr, idx + 1, cur_sum, target) + count_subseq_sum(arr, idx + 1, cur_sum + arr[idx], target)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        target = int(tokens[1+n])
        print(count_subseq_sum(nums, 0, 0, target))
if __name__ == '__main__':
    main()