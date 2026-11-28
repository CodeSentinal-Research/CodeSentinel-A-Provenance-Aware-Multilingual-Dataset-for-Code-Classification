
s=input().strip()
result=[]
def flatten(lst):
    for item in lst:
        if isinstance(item,list): flatten(item)
        else: result.append(item)
import ast
flatten(ast.literal_eval(s))
print(*result)
