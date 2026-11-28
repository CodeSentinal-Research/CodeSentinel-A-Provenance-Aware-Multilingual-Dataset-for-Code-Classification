import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        diff = abs(int(tokens[1]))
        arr = sorted(list(map(int, tokens[2:2+n])))
        seen = set()
        found = False
        for x in arr:
            if (x - diff) in seen or (x + diff) in seen:
                found = True
                break
            seen.add(x)
        print("Yes" if found else "No")
if __name__ == '__main__':
    main()