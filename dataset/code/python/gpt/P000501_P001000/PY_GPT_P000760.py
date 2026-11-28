# problem title : Generate All Increasing Numbers with N Digits
# Solve the stated task using standard input and standard output.
import sys
def inc_numbers(n, start, cur):
    if len(cur) == n:
        print(cur)
        return
    for d in range(start, 10):
        inc_numbers(n, d + 1, cur + str(d))
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        if n == 1: print(0)
        inc_numbers(n, 1, "")
if __name__ == '__main__':
    main()
