# problem title : Reverse First K Elements of Queue
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        q = list(map(int, tokens[1:1+n]))
        k = int(tokens[1+n])
        q = q[:k][::-1] + q[k:]
        print(*q)
if __name__ == '__main__':
    main()
