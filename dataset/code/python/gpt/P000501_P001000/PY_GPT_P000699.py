# problem title : Reverse an Array Using Recursion
# Solve the stated task using standard input and standard output.
import sys
def rev_arr_rec(arr, l, r):
    if l >= r: return
    arr[l], arr[r] = arr[r], arr[l]
    rev_arr_rec(arr, l + 1, r - 1)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        rev_arr_rec(nums, 0, n - 1)
        print(*nums)
if __name__ == '__main__':
    main()
