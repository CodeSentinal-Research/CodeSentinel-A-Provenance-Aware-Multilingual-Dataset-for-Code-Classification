# problem title : Subset Sum
# Solve the stated task using standard input and standard output.
import sys
def subset_sum(arr, idx, cur_sum, res):
    if idx == len(arr):
        res.append(cur_sum)
        return
    subset_sum(arr, idx + 1, cur_sum, res)
    subset_sum(arr, idx + 1, cur_sum + arr[idx], res)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        res = []
        subset_sum(nums, 0, 0, res)
        print(*sorted(res))
if __name__ == '__main__':
    main()
