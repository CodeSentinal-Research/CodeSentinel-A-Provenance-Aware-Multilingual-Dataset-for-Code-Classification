import sys
def gen_bin(n, cur):
    if len(cur) == n:
        print(cur)
        return
    gen_bin(n, cur + "0")
    gen_bin(n, cur + "1")
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        gen_bin(n, "")
if __name__ == '__main__':
    main()