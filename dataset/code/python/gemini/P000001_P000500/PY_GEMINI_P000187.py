import sys
def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        n = int(lines[0])
        arr = set(int(x) for x in lines[1:n+1])
        val = 1
        while val in arr:
            val += 1
        print(val)
if __name__ == '__main__':
    main()