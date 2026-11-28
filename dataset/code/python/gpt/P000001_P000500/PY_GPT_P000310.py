# problem title : Add Binary
# Add binary digits from right to left while carrying into the next position.
a=input().strip(); b=input().strip(); i=len(a)-1;j=len(b)-1;carry=0;out=[]
while i>=0 or j>=0 or carry:
    v=carry+(int(a[i]) if i>=0 else 0)+(int(b[j]) if j>=0 else 0); out.append(str(v%2)); carry=v//2;i-=1;j-=1
print(''.join(reversed(out)))
