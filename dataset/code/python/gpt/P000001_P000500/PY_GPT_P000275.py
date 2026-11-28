# problem title : String Compression
# Run-length encoding stores each consecutive character with its count.
s=input(); out=[]; i=0
while i<len(s):
    j=i
    while j<len(s) and s[j]==s[i]: j+=1
    out.append(s[i]+str(j-i)); i=j
print(''.join(out))
