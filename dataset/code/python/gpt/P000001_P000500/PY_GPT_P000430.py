# problem title : Linear Search from End
# Reverse traversal finds the last occurrence directly.
n,t=map(int,input().split());a=list(map(int,input().split()));print(next((i for i in range(n-1,-1,-1) if a[i]==t),-1))
