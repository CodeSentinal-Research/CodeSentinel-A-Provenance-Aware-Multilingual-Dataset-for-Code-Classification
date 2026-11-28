def count_ways(expression):
    if len(expression) == 1:
        return 1

    if len(expression) == 3:
        op = expression[1]
        if op == '+':
            return max(int(expression[0]), int(expression[2]))
        elif op == '-':
            return max(int(expression[0]), abs(int(expression[2])))
        elif op == '*':
            return int(expression[0]) * int(expression[2])

    max_value = 0
    for i in range(1, len(expression) - 1):
        val = expression[i]

        left_val = count_ways(expression[:i])
        right_val = count_ways(expression[i + 1:])

        if expression[i] == '+':
            max_value = max(max_value, left_val + right_val)
        elif expression[i] == '-':
            max_value = max(max_value, left_val - right_val)
        elif expression[i] == '*':
            max_value = max(max_value, left_val * right_val)

    return max_value

def main():
    expression = input().split()
    print(count_ways(expression))

if __name__ == "__main__":
    main()
This python code will solve the problem as required. It first checks if there is only one number in the expression and returns 1 if it is, because there is only one way to parenthesize a single number. Then it checks if there are two numbers in the expression and returns the maximum possible value of these two numbers. For the rest of the cases, it computes the value of the expression by considering each operator and recursively calls the function on the parts of the expression. It then returns the maximum possible value from all the recursive calls.