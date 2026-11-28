
n=int(input());a=list(map(int,input().split()))
import functools,operator
print(functools.reduce(operator.xor,a,0))
