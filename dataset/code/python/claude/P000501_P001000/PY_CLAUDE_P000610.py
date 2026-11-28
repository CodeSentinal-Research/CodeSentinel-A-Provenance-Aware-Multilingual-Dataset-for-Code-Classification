
n=int(input());a=list(map(int,input().split()))
m=int(input());b=list(map(int,input().split()))
num1=int(''.join(map(str,a)));num2=int(''.join(map(str,b)))
res=str(num1+num2);print(*list(res))
