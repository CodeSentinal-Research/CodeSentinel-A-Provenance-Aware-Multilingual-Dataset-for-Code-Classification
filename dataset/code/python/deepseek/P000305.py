Here is the Python code for the problem:

from collections import deque
import re

def calculate(s):
    s = '(' + s + ')'
    s = re.sub(r'\s+', '', s)
    d = deque()
    sign = '+'
    num = 0
    for c in s:
        if c.isdigit():
            num = num*10 + int(c)
        if c in '+-()' or c.isspace() and d:
            if sign == '+':
                d.append(num)
            if sign == '-':
                d.append(-num)
            if sign == '*':
                d.append(d.popleft() * num)
            if sign == '/':
                d.append(int(d.popleft() / num))
            num = 0
            sign = c
        if c == '(' or c.isspace():
            continue
    return sum(d)

print(calculate("1+2*3-4/2"))

This program uses a deque for a stack, and a simple algorithm to parse the string into tokens.

It handles the parentheses and signs directly, without worrying about operator precedence or unary negatives. It also works with spaces around the operators.

The time complexity is O(n), where n is the length of the string.

The space complexity is also O(n), because at most, all numbers and signs are stored in the stack.