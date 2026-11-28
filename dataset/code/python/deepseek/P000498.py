Here is the Python code for the problem:

def calculate(s):
    def helper(s):
        stack = []
        sign = '+'
        num = 0
        s = '+' + s + '+'
        for i in range(len(s)):
            if s[i].isdigit():
                num = num * 10 + int(s[i])
            elif s[i] in '+-(':
                if sign == '+':
                    stack.append(num)
                elif sign == '-':
                    stack.append(-num)
                elif sign == '(':
                    stack.append(num)
                    num = 0
                elif sign == ')':
                    tmp = 0
                    while stack[-1] != '(':
                        tmp += stack.pop()
                    num = stack.pop() * tmp
                sign = s[i]
                num = 0
            elif s[i] == ' ':
                continue
        return sum(stack)

    return helper(s)

print(calculate("1 + 2 * 3"))
print(calculate("2*(5+4)-3"))
print(calculate("10 + 20 * 3"))
print(calculate("100 * 20 + 200"))

In this code, we're using a stack to handle the arithmetic operations. We iterate over each character of the string, and if it's a digit, we append it to our number. If it's a sign (either + or -), we add the current number to our stack and update our current number. If it's a '(', we push the current number and reset the current number. If it's a ')', we calculate the result until we see a '(' and pop it from the stack. We then append the result to our stack. Finally, we sum up all the elements in our stack to get the result.