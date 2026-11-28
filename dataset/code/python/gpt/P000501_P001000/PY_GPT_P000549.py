# problem title : Stack Permutation Check
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        inp = list(map(int, tokens[1:1+n]))
        out = list(map(int, tokens[1+n:1+2*n]))
        stack = []
        j = 0
        for x in inp:
            stack.append(x)
            while stack and j < n and stack[-1] == out[j]:
                stack.pop()
                j += 1
        print("true" if j == n else "false")
if __name__ == '__main__':
    main()
