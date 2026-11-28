# problem title : Shortest Unsorted Continuous Subarray
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        sorted_nums = sorted(nums)
        l, r = 0, n - 1
        while l < n and nums[l] == sorted_nums[l]: l += 1
        while r > l and nums[r] == sorted_nums[r]: r -= 1
        print(r - l + 1 if r >= l else 0)
if __name__ == '__main__':
    main()
