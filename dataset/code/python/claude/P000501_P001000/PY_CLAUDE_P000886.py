
n=int(input())
print('true' if n>0 and n%sum(int(d) for d in str(n))==0 else 'false')
