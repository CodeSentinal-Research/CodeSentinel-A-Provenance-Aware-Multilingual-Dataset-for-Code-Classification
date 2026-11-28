Here is the Python code to solve this problem:

def evaluate(tokens):
    stack = []
    for token in tokens:
        if token in ['+', '-', '*', '/']:
            num2 = stack.pop()
            num1 = stack.pop()
            if token == '+':
                stack.append(num1 + num2)
            elif token == '-':
                stack.append(num1 - num2)
            elif token == '*':
                stack.append(num1 * num2)
            elif token == '/':
                stack.append(int(num1 / float(num2)))  
        else:
            stack.append(token)
    return stack[0]

print(evaluate(["3", "1", "2", "+", "*"]) ) 
print(evaluate(["4", "13", "5", "/", "+"]) 

This program uses a stack to evaluate the postfix notation expression. For every operator, it pops two numbers from the stack and applies the operator to them, then pushes the result back to the stack. For every operand, it pushes the operand directly to the stack. The final result is the only remaining element in the stack.