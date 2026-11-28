# problem title : Generate All K-Length Strings from Given Characters
# Solve the stated task using standard input and standard output.
import sys
def gen_k_strings(chars, k, cur):
    if len(cur) == k:
        print(cur)
        return
    for c in chars:
        gen_k_strings(chars, k, cur + c)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        chars = sorted(tokens[1:1+n])
        k = int(tokens[1+n])
        gen_k_strings(chars, k, "")
if __name__ == '__main__':
    main()
