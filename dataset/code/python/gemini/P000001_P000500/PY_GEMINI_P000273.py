import sys
def main():
    lines = sys.stdin.read().split()
    if lines:
        s = lines[0]
        # Monotonic stack to track visible elements
        stack = []
        mapping = {')': '(', '}': '{', ']': '['}
        for char in s:
            if char in mapping:
                top = stack.pop() if stack else '#'
                if mapping[char] != top:
                    print('Invalid')
                    return
            else:
                stack.append(char)
        print('Valid' if not stack else 'Invalid')
if __name__ == '__main__':
    main()