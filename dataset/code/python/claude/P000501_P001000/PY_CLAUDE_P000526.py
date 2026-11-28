
s=input().strip()
result=[]
for token in s.replace('[','').replace(']','').split(','):
    token=token.strip()
    if token and token!='-': result.append(int(token))
print(*result)
