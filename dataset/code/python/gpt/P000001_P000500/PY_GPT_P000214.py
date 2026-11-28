# problem title : Find All Numbers Disappeared in Array
# Mark every value that occurs; unmarked values in 1..N are missing.
n=int(input()); a=list(map(int,input().split())); seen=set(a); print(*[x for x in range(1,n+1) if x not in seen])
