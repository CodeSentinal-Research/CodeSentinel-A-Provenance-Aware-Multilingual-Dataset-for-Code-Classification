import sys

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        strings = tokens[1:n+1]
        min_idx = 0
        for i in range(1, n):
            if len(strings[i]) < len(strings[min_idx]):
                min_idx = i
        print(min_idx)

if __name__ == '__main__':
    main()