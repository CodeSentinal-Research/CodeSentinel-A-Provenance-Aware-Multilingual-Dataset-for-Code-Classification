Here is the Python code for the problem:

import re
import operator as op

def calculate(s):
    ops = {'+': op.add, '-': op.sub, '*': op.mul, '/': op.truediv}
    s = re.sub(r'\d+', ' int(', s)
    s = re.sub(r'\D', ' ', s)
    s = re.sub(r'\s+', ' ', s)
    tokens = s.split()
    tokens = [t for t in tokens if t]
    tokens = [t for t in tokens if t not in ('int(', ')')]
    stack = []
    for token in tokens:
        if token == '(':
            stack.append(token)
        elif token in ops:
            while stack and stack[-1] in ops and ops[token].__name__ in ops[stack[-1]].__name__:
                right = stack.pop()
                left = stack.pop()
                result = ops[stack.pop()](left, right)
                stack.append(result)
            stack.append(token)
        elif token == ')':
            while stack[-1] != '(':
                right = stack.pop()
                left = stack.pop()
                result = ops[stack.pop()](left, right)
                stack.append(result)
            stack.pop()
        else:
            stack.append(int(token))
    while stack:
        return stack[0]

def main():
    s = input()
    print(calculate(s))

if __name__ == "__main__":
    main()

In this code, we first define a dictionary to map the operators to their corresponding functions. Then, we use `re.sub` to replace all digits and operators with their equivalent strings. The strings are separated by spaces, and then they are separated by spaces again into tokens. Finally, we use a stack to handle the parentheses and calculate the result.

Please run this script in your local environment to test it.