

n=int(input());a=list(map(int,input().split()))
print('true' if all(a[i]<=a[i+1] for i in range(len(a)-1)) else 'false')
