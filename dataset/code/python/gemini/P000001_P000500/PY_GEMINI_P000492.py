import sys
def main():
    path = sys.stdin.read().strip()
    if path:
        parts = path.split('/')
        # Monotonic stack to track visible elements
        stack = []
        for p in parts:
            if p == '' or p == '.': continue
            elif p == '..':
                # Can also see the next taller person
                if stack: stack.pop()
            else:
                stack.append(p)
        print('/' + '/'.join(stack))
if __name__ == '__main__':
    main()