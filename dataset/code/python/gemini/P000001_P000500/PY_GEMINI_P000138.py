import sys
def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        m, n = int(lines[0]), int(lines[1])
        arr1 = [int(x) for x in lines[2:2+m]]
        arr2 = [int(x) for x in lines[2+m:2+m+n]]
        merged = sorted(arr1 + arr2)
        print(' '.join(str(x) for x in merged))
if __name__ == '__main__':
    main()