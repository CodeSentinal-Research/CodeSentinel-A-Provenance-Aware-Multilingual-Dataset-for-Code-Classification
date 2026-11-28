Here is the Python code:

from itertools import permutations

def add_parentheses(numbers, operations):
    permutations_list = list(permutations(numbers, len(numbers)))
    result_list = []

    operations_list = list(permutations(operations, len(operations)))

    for permutation in permutations_list:
        for operation_permutation in operations_list:
            expression = str(permutation[0])
            for i in range(1, len(permutation)):
                expression += operation_permutation[i - 1] + str(permutation[i])
            result_list.append(eval(expression))

    result_list = sorted(result_list)
    print(result_list)


def main():
    numbers, operations = input().split()
    numbers = list(map(int, numbers))
    operations = ['+', '-', '*']

    add_parentheses(numbers, operations)


if __name__ == "__main__":
    main()

This program reads the numbers and operations from input, generates all possible combinations of parentheses and adds the numbers and operations, and then sorts and prints the results.

Please note that the use of eval function is a dangerous way of doing things because it can evaluate arbitrary Python code. In a real-world scenario, you should validate the input to ensure that it's safe to use.