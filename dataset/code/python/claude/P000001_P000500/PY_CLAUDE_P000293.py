
n=int(input())
strs=[input() for _ in range(n)]

enc=''.join(f'{len(s)}#{s}' for s in strs)
print(enc)

dec=[];i=0
while i<len(enc):
    j=enc.index('#',i);l=int(enc[i:j]);dec.append(enc[j+1:j+1+l]);i=j+1+l
print(*dec)
