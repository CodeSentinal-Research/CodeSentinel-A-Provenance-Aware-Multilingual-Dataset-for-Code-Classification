import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = list(map(int, tokens[1:1+n]))
        cur = 0
        group_len = 1
        res = []
        while cur < n:
            actual_len = min(group_len, n - cur)
            chunk = vals[cur:cur+actual_len]
            if actual_len % 2 == 0:
                res.extend(chunk[::-1])
            else:
                res.extend(chunk)
            cur += actual_len
            group_len += 1
        print(*res)
if __name__ == '__main__':
    main()