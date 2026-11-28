# problem title : Recursive Selection Sort
# Solve the stated task using standard input and standard output.
import sys
def sel_sort_rec(arr, idx, n):
    if idx >= n - 1: return
    min_idx = idx
    for i in range(idx + 1, n):
        if arr[i] < arr[min_idx]: min_idx = i
    arr[idx], arr[min_idx] = arr[min_idx], arr[idx]
    sel_sort_rec(arr, idx + 1, n)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        sel_sort_rec(nums, 0, n)
        print(*nums)
if __name__ == '__main__':
    main()
