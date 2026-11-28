
n=int(input());a=list(map(int,input().split()))
ones=twos=0
for v in a:
    ones=(ones^v)&~twos
    twos=(twos^v)&~ones
print(ones)
