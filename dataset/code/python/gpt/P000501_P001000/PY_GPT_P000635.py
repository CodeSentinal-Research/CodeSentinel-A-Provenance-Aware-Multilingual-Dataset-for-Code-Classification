# problem title : Reverse Nodes in Variable Sized Groups
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = list(map(int, tokens[1:1+n]))
        g = int(tokens[1+n])
        groups = list(map(int, tokens[2+n:2+n+g]))
        cur = 0
        res = []
        for sz in groups:
            if cur + sz <= n:
                res.extend(vals[cur:cur+sz][::-1])
                cur += sz
            else:
                break
        res.extend(vals[cur:])
        print(*res)
if __name__ == '__main__':
    main()
