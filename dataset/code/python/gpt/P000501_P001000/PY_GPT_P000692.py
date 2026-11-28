# problem title : Check if Array is Sorted Using Recursion
# Solve the stated task using standard input and standard output.
import sys
def is_sorted_rec(arr, idx):
    if idx >= len(arr) - 1: return True
    if arr[idx] > arr[idx + 1]: return False
    return is_sorted_rec(arr, idx + 1)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        print("true" if is_sorted_rec(nums, 0) else "false")
if __name__ == '__main__':
    main()
