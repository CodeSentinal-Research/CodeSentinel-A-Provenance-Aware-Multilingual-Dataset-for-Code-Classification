import sys

def longest_valid_parentheses(s: str) -> int:
    stack = [-1]
    max_len = 0
    for i, c in enumerate(s):
        if c == '(':
            stack.append(i)
        else:
            stack.pop()
            if not stack:
                stack.append(i)
            else:
                max_len = max(max_len, i - stack[-1])
    return max_len

def main():
    input_data = sys.stdin.read().split()
    if input_data:
        s = input_data[0]
        print(longest_valid_parentheses(s))

if __name__ == '__main__':
    main()