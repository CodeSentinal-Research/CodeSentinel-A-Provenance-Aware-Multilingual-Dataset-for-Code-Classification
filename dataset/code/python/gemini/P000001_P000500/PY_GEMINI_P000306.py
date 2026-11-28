import sys

def calculate_ii(s: str) -> int:
    stack = []
    num = 0
    sign = '+'
    for i, c in enumerate(s):
        if c.isdigit():
            num = num * 10 + int(c)
        if c in '+-*/' or i == len(s) - 1:
            if not c.isdigit() and c not in '+-*/' and i != len(s) - 1:
                continue
            if sign == '+':
                stack.append(num)
            elif sign == '-':
                stack.append(-num)
            elif sign == '*':
                stack.append(stack.pop() * num)
            elif sign == '/':
                prev = stack.pop()
                stack.append(int(prev / num))
            sign = c
            num = 0
    return sum(stack)

def main():
    line = sys.stdin.read().strip()
    if line:
        print(calculate_ii(line))

if __name__ == '__main__':
    main()