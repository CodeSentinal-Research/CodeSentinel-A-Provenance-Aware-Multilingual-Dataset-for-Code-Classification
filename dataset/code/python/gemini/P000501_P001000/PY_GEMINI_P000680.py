import sys
def print_n_to_1(n):
    if n <= 0: return []
    return [n] + print_n_to_1(n - 1)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        print(*print_n_to_1(n))
if __name__ == '__main__':
    main()