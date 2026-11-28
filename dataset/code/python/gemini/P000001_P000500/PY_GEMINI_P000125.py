import sys
def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 3:
        n, target = int(lines[0]), int(lines[1])
        arr = [int(x) for x in lines[2:n+2]]
        seen = {}
        for i, num in enumerate(arr):
            diff = target - num
            if diff in seen:
                print(f"{seen[diff]} {i}")
                return
            seen[num] = i
if __name__ == '__main__':
    main()