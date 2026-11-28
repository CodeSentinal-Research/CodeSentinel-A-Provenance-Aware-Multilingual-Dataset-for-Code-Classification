import sys
def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 3:
        n, target = int(lines[0]), int(lines[1])
        arr = [int(x) for x in lines[2:n+2]]
        print(arr.index(target) if target in arr else -1)
if __name__ == '__main__':
    main()