import sys
def kth_grammar(n, k):
    if n == 1: return 0
    parent = kth_grammar(n - 1, (k + 1) // 2)
    if parent == 0:
        return 0 if k % 2 != 0 else 1
    else:
        return 1 if k % 2 != 0 else 0
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n, k = int(tokens[0]), int(tokens[1])
        print(kth_grammar(n, k))
if __name__ == '__main__':
    main()