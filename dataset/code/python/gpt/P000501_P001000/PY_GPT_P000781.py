# problem title : Running Sum of 1D Array
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        res = []
        cur = 0
        for x in nums:
            cur += x
            res.append(cur)
        print(*res)
if __name__ == '__main__':
    main()
