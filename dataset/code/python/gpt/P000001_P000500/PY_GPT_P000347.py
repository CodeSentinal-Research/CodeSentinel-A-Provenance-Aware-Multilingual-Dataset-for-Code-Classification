# problem title : Reverse String II
# Reverse the first K characters of every 2K block.
s=list(input());k=int(input())
for i in range(0,len(s),2*k):s[i:i+k]=reversed(s[i:i+k])
print(''.join(s))
