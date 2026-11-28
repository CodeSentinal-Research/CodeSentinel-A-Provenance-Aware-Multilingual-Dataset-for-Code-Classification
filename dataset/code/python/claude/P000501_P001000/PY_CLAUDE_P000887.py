
n=int(input())
print('true' if sum(int(d)**2 for d in str(n**2))==n else 'false')
