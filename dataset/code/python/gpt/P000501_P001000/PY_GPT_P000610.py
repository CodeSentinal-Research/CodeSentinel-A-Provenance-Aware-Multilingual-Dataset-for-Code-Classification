# problem title : Merge Nodes Between Zeros
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = list(map(int, tokens[1:1+n]))
        res = []
        cur_sum = 0
        for x in vals[1:]:
            if x == 0:
                res.append(cur_sum)
                cur_sum = 0
            else:
                cur_sum += x
        print(*res)
if __name__ == '__main__':
    main()
