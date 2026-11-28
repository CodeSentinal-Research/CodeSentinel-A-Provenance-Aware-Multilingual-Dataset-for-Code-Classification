
expr=input().strip()
from functools import lru_cache
nums=[int(x) for x in expr if x.isdigit()]
ops=[x for x in expr if x in '+-*']
def calc(a,op,b):
    if op=='+': return a+b
    if op=='-': return a-b
    return a*b
results=[]
def solve(i,cur):
    if i==len(nums): results.append(cur);return
    for op in '+-*': solve(i+1,calc(cur,op,nums[i])) if i<len(nums) else None
results=[nums[0]]
for i in range(len(ops)):
    new=[]
    for prev in results:
        for op in '+-*': new.append(calc(prev,op,nums[i+1]))
    results=new
print(*sorted(set(results)))
