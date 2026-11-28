Sure, here's a python solution using a stack to handle the precedence of operations:

def calculate(s: str) -> int:
    stack = []
    sign = '+'
    num = 0
    s = '+' + s + '+'
    for char in s:
        if char.isdigit():
            num = num * 10 + int(char)
        elif char in '+-*/':
            if sign == '+':
                stack.append(num)
            elif sign == '-':
                stack.append(-num)
            elif sign == '*':
                stack.append(stack.pop() * num)
            else:
                stack.append(int(stack.pop() / num))
            num = 0
            sign = char
    return sum(stack)

def main():
    s = input("Enter the arithmetic expression: ")
    print(calculate(s))

if __name__ == "__main__":
    main()

In this code, we use a stack to handle the operations in the arithmetic expression. The stack is used to keep track of the numbers being processed so far, and the current operation being performed.

We process the string from left to right. If the character is a digit, we add it to the current number (`num`). If the character is a sign, we update the current operation (`sign`) and then add the current number to the stack. If the sign is '+', we only add to the stack. If the sign is '-', we only add to the stack and then negate the result. If the sign is '*', we multiply the current number by the top of the stack and then add the result to the stack. If the sign is '/', we divide the current number by the top of the stack and then add the result to the stack. We then reset `num` to 0 for the next number.

At the end of the string, we just need to sum up all the numbers in the stack.

In the main function, we ask the user for the arithmetic expression and then print the result of `calculate(s)`.

This solution assumes that the input will always be a valid arithmetic expression and that the input will not contain any invalid characters.