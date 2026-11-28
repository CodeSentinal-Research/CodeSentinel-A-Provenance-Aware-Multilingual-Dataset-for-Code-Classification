
n=int(input());a=list(map(int,input().split()));left=int(input());right=int(input())
a[left-1:right]=reversed(a[left-1:right])
print(*a)
