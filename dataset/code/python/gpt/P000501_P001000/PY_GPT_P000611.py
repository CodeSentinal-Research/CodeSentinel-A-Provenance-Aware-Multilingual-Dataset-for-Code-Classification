# problem title : Maximum Twin Sum of a Linked List
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = list(map(int, tokens[1:1+n]))
        max_sum = max(vals[i] + vals[n - 1 - i] for i in range(n // 2))
        print(max_sum)
if __name__ == '__main__':
    main()
