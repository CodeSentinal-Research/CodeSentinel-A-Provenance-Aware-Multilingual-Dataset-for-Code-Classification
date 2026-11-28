# problem title : Basic Calculator III
# Solve the stated task using standard input and standard output.
import sys
def calculate(s):
    def helper(it):
        stack = []
        num = 0
        sign = '+'
        while (c := next(it, None)) is not None:
            if c.isdigit():
                num = num * 10 + int(c)
            elif c == '(':
                num = helper(it)
            if c in "+-*/)" or (next_char := next(it, None)) is None:
                if c is None and next_char is None: pass
                if sign == '+': stack.append(num)
                elif sign == '-': stack.append(-num)
                elif sign == '*': stack.append(stack.pop() * num)
                elif sign == '/': stack.append(int(stack.pop() / num))
                if c == ')':
                    break
                sign = c
                num = 0
        return sum(stack)

    # Simplified parser
    def parse(s):
        st = []
        num = 0
        sign = '+'
        i = 0
        while i < len(s):
            c = s[i]
            if c.isdigit():
                num = num * 10 + int(c)
            elif c == '(':
                j, count = i, 0
                while i < len(s):
                    if s[i] == '(': count += 1
                    if s[i] == ')': count -= 1
                    if count == 0: break
                    i += 1
                num = parse(s[j+1:i])
            if c in "+-*/" or i == len(s) - 1:
                if sign == '+': st.append(num)
                elif sign == '-': st.append(-num)
                elif sign == '*': st.append(st.pop() * num)
                elif sign == '/': st.append(int(st.pop() / num))
                sign = c
                num = 0
            i += 1
        return sum(st)

    return parse(s.replace(" ", ""))

def main():
    s = sys.stdin.read().strip()
    if s:
        print(calculate(s))
if __name__ == '__main__':
    main()
