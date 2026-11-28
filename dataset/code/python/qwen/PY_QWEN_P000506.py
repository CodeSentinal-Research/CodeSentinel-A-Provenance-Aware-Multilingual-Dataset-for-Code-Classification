s = input().strip().replace(" ", "")
def calc(it):
    stack = []
    num = 0
    sign = '+'
    while it:
        c = next(it, None)
        if c is None: break
        if c.isdigit():
            num = num * 10 + int(c)
        elif c == '(':
            num = calc(it)
        elif c == ')':
            pass
        else:
            if sign == '+': stack.append(num)
            elif sign == '-': stack.append(-num)
            elif sign == '*': stack.append(stack.pop() * num)
            elif sign == '/': stack.append(int(stack.pop() / num))
            sign = c
            num = 0
            if c == ')': break
    if sign == '+': stack.append(num)
    elif sign == '-': stack.append(-num)
    elif sign == '*': stack.append(stack.pop() * num)
    elif sign == '/': stack.append(int(stack.pop() / num))
    return sum(stack)
print(calc(iter(s)))
