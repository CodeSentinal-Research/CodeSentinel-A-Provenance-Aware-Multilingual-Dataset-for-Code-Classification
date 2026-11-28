# problem title : Reorder Linked List
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = list(map(int, tokens[1:1+n]))
        res = []
        l, r = 0, n - 1
        while l <= r:
            if l == r:
                res.append(vals[l])
            else:
                res.append(vals[l])
                res.append(vals[r])
            l += 1
            r -= 1
        print(*res)
if __name__ == '__main__':
    main()
