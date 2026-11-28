def ternary_expression_parser(expression):
    def evaluate(left, operator, right):
        if operator == '?':
            return 'T' if left == 'T' else 'F'
        else:
            return str(int(left) + int(right) + 1) if operator == ':' else str(int(left) - int(right) - 1)

    stack = []
    for char in expression[::-1]:
        if char.isdigit():
            stack.append(char)
        else:
            right = stack.pop()
            left = stack.pop()
            result = evaluate(left, char, right)
            stack.append(result)
    return stack.pop()


def main():
    expression = input()
    print(ternary_expression_parser(expression))


if __name__ == "__main__":
    main()