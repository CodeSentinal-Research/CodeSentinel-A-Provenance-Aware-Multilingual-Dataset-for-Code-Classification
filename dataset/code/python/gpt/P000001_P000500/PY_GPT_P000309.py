# problem title : Multiply Strings
# Schoolbook multiplication uses one digit position per output cell.
a=input().strip(); b=input().strip()
if a=='0' or b=='0': print('0')
else:
    z=[0]*(len(a)+len(b))
    for i in range(len(a)-1,-1,-1):
        for j in range(len(b)-1,-1,-1): z[i+j+1]+=int(a[i])*int(b[j])
    for k in range(len(z)-1,0,-1): z[k-1]+=z[k]//10; z[k]%=10
    print(''.join(map(str,z)).lstrip('0'))
