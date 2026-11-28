# problem title : Count Ways to Climb Stairs
# Solve the stated task using standard input and standard output.
import sys
def climb_stairs(n):
    if n <= 1: return 1
    a, b = 1, 1
    for _ in range(2, n + 1):
        a, b = b, a + b
    return b
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        print(climb_stairs(n))
if __name__ == '__main__':
    main()
