# problem title : Remove Invalid Parentheses
# Solve the stated task using standard input and standard output.
import sys
def is_valid(s):
    cnt = 0
    for c in s:
        if c == '(': cnt += 1
        elif c == ')':
            cnt -= 1
            if cnt < 0: return False
    return cnt == 0
def remove_invalid_parentheses(s):
    level = {s}
    while level:
        valid = sorted([x for x in level if is_valid(x)])
        if valid: return valid
        next_level = set()
        for item in level:
            for i in range(len(item)):
                if item[i] in '()':
                    next_level.add(item[:i] + item[i+1:])
        level = next_level
    return [""]
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        for ans in remove_invalid_parentheses(tokens[0]):
            print(ans)
if __name__ == '__main__':
    main()
