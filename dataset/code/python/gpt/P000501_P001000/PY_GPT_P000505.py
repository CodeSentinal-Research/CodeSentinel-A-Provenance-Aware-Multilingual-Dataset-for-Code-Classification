# problem title : Basic Calculator II
# Solve the stated task using standard input and standard output.
import sys
def calculate(s):
    stack = []
    num = 0
    sign = '+'
    for i, c in enumerate(s):
        if c.isdigit():
            num = num * 10 + int(c)
        if c in "+-*/" or i == len(s) - 1:
            if sign == '+': stack.append(num)
            elif sign == '-': stack.append(-num)
            elif sign == '*': stack.append(stack.pop() * num)
            elif sign == '/': stack.append(int(stack.pop() / num))
            sign = c
            num = 0
    return sum(stack)

def main():
    s = sys.stdin.read().replace(" ", "").strip()
    if s:
        print(calculate(s))
if __name__ == '__main__':
    main()
