import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        arr = list(map(int, tokens[1:1+n]))
        ans = -1
        for i in range(n):
            if arr[i] == i:
                ans = i
                break
        print(ans)
if __name__ == '__main__':
    main()