import sys

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        strings = tokens[1:n+1]
        max_idx = 0
        for i in range(1, n):
            if len(strings[i]) > len(strings[max_idx]):
                max_idx = i
        print(max_idx)

if __name__ == '__main__':
    main()