import sys

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        arr = list(map(int, tokens[1:n+1]))
        min_idx = 0
        for i in range(1, n):
            if arr[i] < arr[min_idx]:
                min_idx = i
        print(min_idx)

if __name__ == '__main__':
    main()