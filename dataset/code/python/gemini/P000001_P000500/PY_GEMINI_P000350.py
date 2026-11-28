import sys

def remove_duplicates_ii(s: str, k: int) -> str:
    stack = []
    for c in s:
        if stack and stack[-1][0] == c:
            stack[-1][1] += 1
            if stack[-1][1] == k:
                stack.pop()
        else:
            stack.append([c, 1])
    return "".join(c * cnt for c, cnt in stack)

def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        print(remove_duplicates_ii(lines[0], int(lines[1])))

if __name__ == '__main__':
    main()