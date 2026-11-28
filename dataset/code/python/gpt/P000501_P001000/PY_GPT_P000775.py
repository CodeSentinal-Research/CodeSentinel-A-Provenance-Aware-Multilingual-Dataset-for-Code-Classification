# problem title : Generate All Binary Strings Without Consecutive Ones
# Solve the stated task using standard input and standard output.
import sys
def gen_no_cons_ones(n, cur):
    if len(cur) == n:
        print(cur)
        return
    gen_no_cons_ones(n, cur + "0")
    if not cur or cur[-1] != '1':
        gen_no_cons_ones(n, cur + "1")
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        gen_no_cons_ones(n, "")
if __name__ == '__main__':
    main()
