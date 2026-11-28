import sys
def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 3:
        n, target = int(lines[0]), int(lines[1])
        arr = [int(x) for x in lines[2:n+2]]
        seen = set()
        for x in arr:
            diff = target - x
            if diff in seen:
                print(f"{diff} {x}")
                return
            seen.add(x)
        print("No Pair")
if __name__ == '__main__':
    main()