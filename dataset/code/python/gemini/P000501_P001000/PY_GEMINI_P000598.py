import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vals = list(map(int, tokens[1:1+n]))
        left = int(tokens[1+n]) - 1
        right = int(tokens[2+n]) - 1
        vals[left:right+1] = vals[left:right+1][::-1]
        print(*vals)
if __name__ == '__main__':
    main()