Sure, here's a Python solution using recursion and backtracking. This code will take a string of digits as input, and generate all valid arithmetic expressions with parentheses.

import itertools

def generate_parentheses(s):
    def dfs(s, p, left, right, op):
        if len(s) == 2*len(p):
            print(''.join(p))
            return
        if left:
            p.append('(')
            dfs(s, p, left-1, right, op+1)
            p.pop()
        if right > left:
            p.append(')')
            dfs(s, p, left, right-1, op)
            p.pop()
    dfs(s, [], 0, 0, 0)

def all_expressions(digits):
    for perm in itertools.permutations(digits):
        perm = ''.join(perm)
        for comb in itertools.combinations(perm, r=len(perm)-1):
            parentheses = list(comb)
            for op in itertools.product(['+', '-', '*'], repeat=len(parentheses)-1):
                expr = ''.join(parentheses + list(op))
                generate_parentheses(expr)

def main():
    digits = input("Enter a string of digits: ")
    all_expressions(digits)

if __name__ == "__main__":
    main()

Please note that this code will only work for digits from 0 to 9. If you want to use other characters, you will need to modify the `all_expressions` function.