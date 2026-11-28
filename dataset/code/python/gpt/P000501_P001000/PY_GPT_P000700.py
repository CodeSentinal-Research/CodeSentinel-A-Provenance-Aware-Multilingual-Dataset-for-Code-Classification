# problem title : Find Maximum Element Using Recursion
# Solve the stated task using standard input and standard output.
import sys
def max_rec(arr, idx):
    if idx == len(arr) - 1: return arr[idx]
    return max(arr[idx], max_rec(arr, idx + 1))
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        print(max_rec(nums, 0))
if __name__ == '__main__':
    main()
