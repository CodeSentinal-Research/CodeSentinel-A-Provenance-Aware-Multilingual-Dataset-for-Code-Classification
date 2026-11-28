# problem title : Remove Duplicates from Unsorted Linked List
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = list(map(int, tokens[1:1+n]))
        seen = set()
        res = []
        for x in vals:
            if x not in seen:
                seen.add(x)
                res.append(x)
        print(*res)
if __name__ == '__main__':
    main()
