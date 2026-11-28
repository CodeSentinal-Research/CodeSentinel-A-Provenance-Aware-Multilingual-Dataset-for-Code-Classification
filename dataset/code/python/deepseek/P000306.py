Here is the Python code with the main function and input handling:

def calculate(s: str) -> int:
    s = s.replace(' ', '')
    stack = []
    sign = '+'
    num = 0
    for i in range(len(s)):
        if s[i].isdigit():
            num = num*10 + int(s[i])
        if s[i] in '+-*/' or i == len(s)-1:
            if sign == '+':
                stack.append(num)
            elif sign == '-':
                stack.append(-num)
            elif sign == '*':
                stack.append(stack.pop() * num)
            else:
                stack.append(int(stack.pop() / num))
            num = 0
            sign = s[i]
    return sum(stack)

def main():
    s = input()
    result = calculate(s)
    print(result)

if __name__ == "__main__":
    main()
This code reads an expression from input, calculates the result and then prints the result. The main function calls the calculate function with the input string.