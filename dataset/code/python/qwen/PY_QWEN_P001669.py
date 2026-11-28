import sys

def solve():
    serialization = sys.stdin.readline().strip().split(',')
    stack = []
    for token in serialization:
        if token == '#':
            if not stack:
                print("NO")
                return
            while stack and stack[-1] == '#':
                stack.pop()
                if not stack:
                    print("NO")
                    return
                stack.pop()
            stack.append('#')
        else:
            stack.append(token)
            
    print("YES" if len(stack) == 1 and stack[0] == '#' else "NO")

solve()

