# problem title : Linear Search Using Recursion
# Solve the stated task using standard input and standard output.
import sys
def lin_search_rec(arr, target, idx):
    if idx >= len(arr): return False
    if arr[idx] == target: return True
    return lin_search_rec(arr, target, idx + 1)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        target = int(tokens[1+n])
        print("true" if lin_search_rec(nums, target, 0) else "false")
if __name__ == '__main__':
    main()
