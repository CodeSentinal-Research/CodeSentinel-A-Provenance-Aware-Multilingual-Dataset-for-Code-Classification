import sys

def count_prefixes(words, s: str) -> int:
    return sum(1 for w in words if s.startswith(w))

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        s = tokens[-1]
        words = tokens[:-1]
        print(count_prefixes(words, s))

if __name__ == '__main__':
    main()