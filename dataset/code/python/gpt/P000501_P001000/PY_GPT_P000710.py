# problem title : Generate All Permutations of an Array
# Solve the stated task using standard input and standard output.
import sys
def perm(nums, cur, used):
    if len(cur) == len(nums):
        print(*cur)
        return
    for i in range(len(nums)):
        if not used[i]:
            used[i] = True
            perm(nums, cur + [nums[i]], used)
            used[i] = False
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        perm(nums, [], [False]*n)
if __name__ == '__main__':
    main()
