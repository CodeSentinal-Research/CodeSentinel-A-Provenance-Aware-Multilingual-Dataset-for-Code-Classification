
s=input().strip();opens=0;closes=0
for c in s:
    if c=='(': opens+=1
    else:
        if opens>0: opens-=1
        else: closes+=1
print(opens+closes)
