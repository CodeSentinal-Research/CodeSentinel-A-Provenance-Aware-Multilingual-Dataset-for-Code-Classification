# problem title : Josephus Problem Using Circular Linked List
# Solve the stated task using standard input and standard output.
import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        k = int(tokens[1])
        ans = 0
        for i in range(1, n + 1):
            ans = (ans + k) % i
        print(ans + 1)
if __name__ == '__main__':
    main()
