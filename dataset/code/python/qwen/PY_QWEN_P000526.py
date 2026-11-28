import sys
from collections import defaultdict
def solve():
    s = input().strip()
    stack = [defaultdict(int)]
    i = 0
    while i < len(s):
        if s[i] == '(':
            stack.append(defaultdict(int))
            i += 1
        elif s[i] == ')':
            top = stack.pop()
            num = 0
            i += 1
            while i < len(s) and s[i].isdigit():
                num = num * 10 + int(s[i])
                i += 1
            if num == 0: num = 1
            for k in top:
                stack[-1][k] += top[k] * num
        else:
            elem = s[i]
            i += 1
            while i < len(s) and s[i].islower():
                elem += s[i]
                i += 1
            num = 0
            while i < len(s) and s[i].isdigit():
                num = num * 10 + int(s[i])
                i += 1
            if num == 0: num = 1
            stack[-1][elem] += num
    res = ""
    for k in sorted(stack[-1].keys()):
        res += k + (str(stack[-1][k]) if stack[-1][k] > 1 else "")
    print(res)
solve()
