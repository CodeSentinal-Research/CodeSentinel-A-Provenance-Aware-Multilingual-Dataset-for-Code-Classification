Sure, here is the Python code with main function and input handling.

from itertools import permutations

def addParentheses(expression):
    operators = set(['+', '-', '*'])
    
    permutation_list = permutations(operators, len(expression.split(' ')))
    
    result = []
    
    for perm in permutation_list:
        exp = expression.split(' ')
        for i in range(len(exp)):
            if exp[i] in perm:
                exp[i] = str(perm.index(exp[i]))
        res = eval(' '.join(exp))
        if res not in result:
            result.append(res)
            
    return sorted(result)

def main():
    expression = input('Enter an expression: ')
    results = addParentheses(expression)
    for result in results:
        print(result)

if __name__ == "__main__":
    main()

In this code, the `addParentheses` function first generates all possible permutations of operators in the expression, then for each permutation, it evaluates the expression using the result. Finally, it sorts and returns all the unique results.

The `main` function is the entry point of the program, and it gets the expression from the user and prints all the possible results.