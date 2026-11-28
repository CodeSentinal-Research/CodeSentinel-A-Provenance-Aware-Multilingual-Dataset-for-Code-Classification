# problem title : Recursive Insertion Sort
# Solve the stated task using standard input and standard output.
import sys
def ins_sort_rec(arr, n):
    if n <= 1: return
    ins_sort_rec(arr, n - 1)
    last = arr[n - 1]
    j = n - 2
    while j >= 0 and arr[j] > last:
        arr[j + 1] = arr[j]
        j -= 1
    arr[j + 1] = last
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        ins_sort_rec(nums, n)
        print(*nums)
if __name__ == '__main__':
    main()
