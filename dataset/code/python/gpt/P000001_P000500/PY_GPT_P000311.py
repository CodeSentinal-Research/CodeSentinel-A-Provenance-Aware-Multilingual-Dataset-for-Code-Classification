# problem title : Add Strings
# Decimal strings can be added digit by digit without converting to integers.
a=input().strip(); b=input().strip(); i=len(a)-1;j=len(b)-1;c=0;o=[]
while i>=0 or j>=0 or c:
    v=c+(ord(a[i])-48 if i>=0 else 0)+(ord(b[j])-48 if j>=0 else 0);o.append(chr(48+v%10));c=v//10;i-=1;j-=1
print(''.join(reversed(o)))
