# problem title : Find the Middle Index in Array
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        total = sum(nums)
        left_sum = 0
        ans = -1
        for i in range(n):
            if left_sum == total - left_sum - nums[i]:
                ans = i
                break
            left_sum += nums[i]
        print(ans)
if __name__ == '__main__':
    main()
