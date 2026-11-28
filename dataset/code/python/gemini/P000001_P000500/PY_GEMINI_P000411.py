import sys
def main():
    lines = sys.stdin.read().splitlines()
    if lines:
        n = int(lines[0].strip())
        records = lines[1:n+1]
        keyword = lines[n+1].strip()
        for r in records:
            if keyword in r:
                print(r)
if __name__ == '__main__':
    main()