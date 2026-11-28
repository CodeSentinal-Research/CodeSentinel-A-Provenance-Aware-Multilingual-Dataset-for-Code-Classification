Here is the Python code for the problem:

def parse_bool_expr(expression):
    operators = {
        '!': lambda x: not x,
        '|': lambda x, y: x or y,
        '&': lambda x, y: x and y
    }

    def evaluate(expression):
        stack = []

        for char in expression:
            if char == '(':
                stack.append(char)
            elif char == ')':
                sub_exp = []
                while stack[-1] != '(':
                    sub_exp.append(stack.pop())
                stack.pop()
                result = operators[char](evaluate(''.join(sub_exp)))
                stack.append(result)
            elif char in operators:
                if len(stack) < 2:
                    raise ValueError('Missing operands')
                operands = [stack.pop(), stack.pop()]
                result = operators[char](*operands)
                stack.append(result)
            elif char == 'f' or char == 't':
                stack.append(char == 'f')
            else:
                raise ValueError('Invalid character')

        if len(stack) != 1:
            raise ValueError('Invalid expression')

        return stack[0]

    return evaluate(expression)


def main():
    expression = input("Enter a boolean expression: ")
    print(parse_bool_expr(expression))


if __name__ == "__main__":
    main()

This program uses a stack to keep track of the operands and the operators. It uses a dictionary to map the operator characters to the actual operator function. The evaluate function is a recursive function that parses the input expression from left to right. It uses a stack to keep track of the parentheses. When it encounters a '(', it pushes it to the stack. When it encounters a ')', it pops all the elements from the stack until it encounters a '('. This popped element is the sub-expression that the ')' wraps. Then it evaluates the sub-expression and pushes the result to the stack. When it encounters an operator, it pops two operands from the stack and applies the operator to these operands.