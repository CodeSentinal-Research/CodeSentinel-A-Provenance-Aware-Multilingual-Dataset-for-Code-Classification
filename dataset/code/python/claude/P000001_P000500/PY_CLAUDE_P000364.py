
n=int(input());s=set(map(int,input().split()));q=int(input())
for _ in range(q): x=int(input());print('Found' if x in s else 'Not Found')
