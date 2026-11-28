import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        arr = list(map(int, tokens[1:n]))
        diff = (arr[-1] - arr[0]) // (n - 1)
        for i in range(len(arr) - 1):
            if arr[i+1] - arr[i] != diff:
                print(arr[i] + diff)
                return
        print(arr[-1] + diff)
if __name__ == '__main__':
    main()