# problem title : Generate All Strings of Balanced Parentheses
# Solve the stated task using standard input and standard output.
import sys
def gen_par(n, o, c, cur):
    if len(cur) == 2 * n:
        print(cur)
        return
    if o < n: gen_par(n, o + 1, c, cur + "(")
    if c < o: gen_par(n, o, c + 1, cur + ")")
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        gen_par(n, 0, 0, "")
if __name__ == '__main__':
    main()
