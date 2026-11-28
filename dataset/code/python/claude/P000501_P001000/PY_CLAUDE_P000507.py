
s=input().strip();nodes=s.split(',')
slots=1
for n in nodes:
    if slots==0: print('false');exit()
    slots-=1
    if n!='#': slots+=2
print('true' if slots==0 else 'false')
