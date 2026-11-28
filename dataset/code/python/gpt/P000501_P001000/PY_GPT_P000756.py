# problem title : Recursive Quick Sort
# Solve the stated task using standard input and standard output.
import sys
def quick_sort(arr, l, r):
    if l >= r: return
    pivot = arr[r]
    p_idx = l
    for i in range(l, r):
        if arr[i] < pivot:
            arr[i], arr[p_idx] = arr[p_idx], arr[i]
            p_idx += 1
    arr[p_idx], arr[r] = arr[r], arr[p_idx]
    quick_sort(arr, l, p_idx - 1)
    quick_sort(arr, p_idx + 1, r)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        quick_sort(nums, 0, n - 1)
        print(*nums)
if __name__ == '__main__':
    main()
