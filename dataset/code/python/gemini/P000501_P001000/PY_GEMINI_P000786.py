import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        total = sum(nums)
        left = 0
        ans = []
        for x in nums:
            right = total - left - x
            ans.append(abs(left - right))
            left += x
        print(*ans)
if __name__ == '__main__':
    main()