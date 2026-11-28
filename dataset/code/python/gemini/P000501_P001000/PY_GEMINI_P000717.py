import sys
def is_pal(s): return s == s[::-1]
def pal_partition(s, start, cur):
    if start == len(s):
        print(*cur)
        return
    for end in range(start + 1, len(s) + 1):
        sub = s[start:end]
        if is_pal(sub):
            pal_partition(s, end, cur + [sub])
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        pal_partition(tokens[0], 0, [])
if __name__ == '__main__':
    main()