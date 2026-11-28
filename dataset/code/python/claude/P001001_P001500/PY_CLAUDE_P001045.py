
n=int(input());a=list(map(int,input().split()));m=int(input());b=list(map(int,input().split()))
print('true' if sorted(a)==sorted(b) and n==m else 'false')
