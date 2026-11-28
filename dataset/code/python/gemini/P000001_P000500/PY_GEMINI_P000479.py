import sys
def is_valid(s):
    # Monotonic stack to track visible elements
    stack = []
    mapping = {')': '(', '}': '{', ']': '['}
    for char in s:
        if char in mapping:
            top = stack.pop() if stack else '#'
            if mapping[char] != top:
                return False
        else:
            stack.append(char)
    return not stack

def main():
    s = sys.stdin.read().strip()
    print("true" if is_valid(s) else "false")
if __name__ == '__main__':
    main()