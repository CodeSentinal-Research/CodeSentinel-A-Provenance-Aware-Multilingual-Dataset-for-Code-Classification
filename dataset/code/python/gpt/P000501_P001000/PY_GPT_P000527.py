# problem title : Parse Boolean Expression
# Solve the stated task using standard input and standard output.
import sys
def parseBoolExpr(expression):
    stack = []
    for c in expression:
        if c in ",(":
            continue
        elif c in "tf!&|":
            stack.append(c)
        elif c == ')':
            seen_t = seen_f = False
            while stack and stack[-1] in "tf":
                val = stack.pop()
                if val == 't': seen_t = True
                if val == 'f': seen_f = True
            op = stack.pop()
            if op == '!':
                stack.append('f' if seen_t else 't')
            elif op == '&':
                stack.append('f' if seen_f else 't')
            elif op == '|':
                stack.append('t' if seen_t else 'f')
    return stack[0] == 't'

def main():
    s = sys.stdin.read().strip()
    if s:
        print("true" if parseBoolExpr(s) else "false")
if __name__ == '__main__':
    main()
