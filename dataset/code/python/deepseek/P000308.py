def generate_results(expression):
    def compute(expression):
        if expression.isdigit():
            return int(expression)

        left, op, right = expression[0], expression[1], expression[2]

        if op == '+':
            return compute(left) + compute(right)
        elif op == '-':
            return compute(left) - compute(right)
        elif op == '*':
            return compute(left) * compute(right)
        elif op == '/':
            return compute(left) / compute(right)

    expressions = [expression]
    for _ in range(len(expression) - 2):
        expressions += [e[i] + e[i+1] + e[i+2] for i in range(len(expression) - 2)]

    results = set()
    for expression in expressions:
        results.add(compute(expression))

    return results

def solve_problem(expression):
    results = generate_results(expression)
    print(sorted(results))

def main():
    expression = input()
    solve_problem(expression)

if __name__ == "__main__":
    main()