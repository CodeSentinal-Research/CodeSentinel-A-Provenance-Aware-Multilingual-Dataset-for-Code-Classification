# problem title : Find Last Occurrence of an Element
# Reverse enumeration finds the last matching position without extra sorting.
n=int(input());a=list(map(int,input().split()));x=int(input());print(next((i for i in range(n-1,-1,-1) if a[i]==x),-1))
