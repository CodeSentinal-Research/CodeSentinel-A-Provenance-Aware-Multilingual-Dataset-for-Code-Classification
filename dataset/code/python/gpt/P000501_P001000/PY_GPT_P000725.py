# problem title : Split String into Descending Consecutive Values
# Solve the stated task using standard input and standard output.
import sys
def split_descending(s):
    def backtrack(idx, prev):
        if idx == len(s): return True
        cur = 0
        for i in range(idx, len(s)):
            cur = cur * 10 + int(s[i])
            if cur == prev - 1:
                if backtrack(i + 1, cur): return True
            elif cur >= prev:
                break
        return False
    first = 0
    for i in range(len(s) - 1):
        first = first * 10 + int(s[i])
        if backtrack(i + 1, first): return True
    return False
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        print("true" if split_descending(tokens[0]) else "false")
if __name__ == '__main__':
    main()
