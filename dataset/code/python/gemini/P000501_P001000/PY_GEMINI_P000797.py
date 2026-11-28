import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        counts = {0: 1}
        cur = 0
        ans = 0
        for x in nums:
            cur += (1 if x == 1 else -1)
            ans += counts.get(cur, 0)
            counts[cur] = counts.get(cur, 0) + 1
        print(ans)
if __name__ == '__main__':
    main()