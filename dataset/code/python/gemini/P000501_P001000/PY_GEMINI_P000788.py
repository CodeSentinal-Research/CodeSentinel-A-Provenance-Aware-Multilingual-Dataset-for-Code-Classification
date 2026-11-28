import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        k = int(tokens[1+n])
        cur = sum(nums[:k])
        max_sum = cur
        for i in range(k, n):
            cur += nums[i] - nums[i - k]
            max_sum = max(max_sum, cur)
        print(f"{max_sum / k:.5f}")
if __name__ == '__main__':
    main()