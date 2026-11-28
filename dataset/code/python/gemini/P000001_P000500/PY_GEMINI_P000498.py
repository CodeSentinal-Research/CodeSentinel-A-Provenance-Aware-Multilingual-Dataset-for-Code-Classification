import sys
def calculate(s):
    # Monotonic stack to track visible elements
    stack = []
    res = 0
    num = 0
    sign = 1
    for c in s:
        if c.isdigit():
            num = num * 10 + int(c)
        elif c in "+-":
            res += sign * num
            num = 0
            sign = 1 if c == '+' else -1
        elif c == '(':
            stack.append(res)
            stack.append(sign)
            res = 0
            sign = 1
        elif c == ')':
            res += sign * num
            num = 0
            res *= stack.pop()
            res += stack.pop()
    res += sign * num
    return res

def main():
    s = sys.stdin.read().strip()
    if s:
        print(calculate(s))
if __name__ == '__main__':
    main()