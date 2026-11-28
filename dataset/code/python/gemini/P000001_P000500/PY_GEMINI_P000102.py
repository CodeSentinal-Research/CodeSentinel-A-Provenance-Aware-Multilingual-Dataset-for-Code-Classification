import sys
def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        n = int(lines[0])
        arr = [int(x) for x in lines[1:n+1]]
        print(min(arr))
if __name__ == '__main__':
    main()