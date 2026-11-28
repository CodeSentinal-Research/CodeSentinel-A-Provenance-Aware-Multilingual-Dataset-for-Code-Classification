# problem title : Basic Calculator
# Recursive descent handles parentheses and + or - with a sign carried into nested expressions.
s=input(); i=0
def calc():
    global i
    total=num=0; sign=1
    while i<len(s):
        ch=s[i]
        if ch.isdigit(): num=num*10+int(ch)
        elif ch in '+-': total+=sign*num; num=0; sign=1 if ch=='+' else -1
        elif ch=='(': i+=1; num=calc()
        elif ch==')': total+=sign*num; i+=1; return total
        i+=1
    return total+sign*num
print(calc())
