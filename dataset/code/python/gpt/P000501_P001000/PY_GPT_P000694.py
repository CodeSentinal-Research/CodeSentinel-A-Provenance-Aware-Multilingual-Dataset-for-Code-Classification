# problem title : Binary Search Using Recursion
# Solve the stated task using standard input and standard output.
import sys
def bin_search_rec(arr, target, l, r):
    if l > r: return -1
    mid = (l + r) // 2
    if arr[mid] == target: return mid
    elif arr[mid] > target: return bin_search_rec(arr, target, l, mid - 1)
    else: return bin_search_rec(arr, target, mid + 1, r)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        target = int(tokens[1+n])
        print(bin_search_rec(nums, target, 0, n - 1))
if __name__ == '__main__':
    main()
