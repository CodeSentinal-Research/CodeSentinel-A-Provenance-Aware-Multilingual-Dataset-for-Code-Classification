import sys

def remove_duplicates(s: str) -> str:
    stack = []
    for c in s:
        if stack and stack[-1] == c:
            stack.pop()
        else:
            stack.append(c)
    return "".join(stack)

def main():
    lines = sys.stdin.read().split()
    if lines:
        print(remove_duplicates(lines[0]))

if __name__ == '__main__':
    main()