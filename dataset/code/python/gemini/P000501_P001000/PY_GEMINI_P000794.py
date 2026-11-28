import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        k = int(tokens[1+n])
        seen = {0: -1}
        cur = 0
        max_len = 0
        for i in range(n):
            cur += nums[i]
            if (cur - k) in seen:
                max_len = max(max_len, i - seen[cur - k])
            if cur not in seen:
                seen[cur] = i
        print(max_len)
if __name__ == '__main__':
    main()