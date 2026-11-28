import sys
from collections import defaultdict
def countOfAtoms(formula):
    stack = [defaultdict(int)]
    i = 0
    n = len(formula)
    while i < n:
        if formula[i] == '(':
            stack.append(defaultdict(int))
            i += 1
        elif formula[i] == ')':
            i += 1
            i_start = i
            while i < n and formula[i].isdigit(): i += 1
            mult = int(formula[i_start:i] or 1)
            top = stack.pop()
            for atom, cnt in top.items():
                stack[-1][atom] += cnt * mult
        else:
            i_start = i
            i += 1
            while i < n and formula[i].islower(): i += 1
            atom = formula[i_start:i]
            i_start = i
            while i < n and formula[i].isdigit(): i += 1
            cnt = int(formula[i_start:i] or 1)
            stack[-1][atom] += cnt
    counts = stack[0]
    return "".join(atom + (str(counts[atom]) if counts[atom] > 1 else "") for atom in sorted(counts))

def main():
    s = sys.stdin.read().strip()
    if s:
        print(countOfAtoms(s))
if __name__ == '__main__':
    main()