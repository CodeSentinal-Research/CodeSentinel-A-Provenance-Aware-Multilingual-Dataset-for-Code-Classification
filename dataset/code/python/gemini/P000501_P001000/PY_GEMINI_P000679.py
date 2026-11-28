import sys
def print_1_to_n(n):
    if n <= 0: return []
    return print_1_to_n(n - 1) + [n]
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        print(*print_1_to_n(n))
if __name__ == '__main__':
    main()