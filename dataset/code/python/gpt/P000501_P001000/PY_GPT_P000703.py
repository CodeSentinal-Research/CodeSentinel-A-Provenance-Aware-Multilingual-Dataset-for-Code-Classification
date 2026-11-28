# problem title : Check if Array is Palindrome Using Recursion
# Solve the stated task using standard input and standard output.
import sys
def is_pal(arr, l, r):
    if l >= r: return True
    if arr[l] != arr[r]: return False
    return is_pal(arr, l + 1, r - 1)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = tokens[1:1+n]
        print("true" if is_pal(nums, 0, n - 1) else "false")
if __name__ == '__main__':
    main()
