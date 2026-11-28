import sys

def simplify_path(path: str) -> str:
    parts = path.split('/')
    stack = []
    for p in parts:
        if p == '' or p == '.':
            continue
        elif p == '..':
            if stack:
                stack.pop()
        else:
            stack.append(p)
    return '/' + '/'.join(stack)

def main():
    lines = sys.stdin.read().split()
    if lines:
        print(simplify_path(lines[0]))

if __name__ == '__main__':
    main()