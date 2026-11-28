
n=int(input())
digits=str(abs(n))
alt=sum(int(d)*(-1 if i%2 else 1) for i,d in enumerate(reversed(digits)))
print('true' if alt%11==0 else 'false')
