# problem title : Delete Nodes Whose Values Occur More Than Once
# Solve the stated task using standard input and standard output.
import sys
from collections import Counter
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = list(map(int, tokens[1:1+n]))
        counts = Counter(vals)
        res = [x for x in vals if counts[x] == 1]
        print(*res)
if __name__ == '__main__':
    main()
