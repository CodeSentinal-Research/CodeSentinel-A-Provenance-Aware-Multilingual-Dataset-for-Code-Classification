# problem title : Roman to Integer
# Subtract a Roman value when it is smaller than the next value; otherwise add it.
s=input().strip(); val={'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}; ans=0
for i,ch in enumerate(s): ans += -val[ch] if i+1<len(s) and val[ch]<val[s[i+1]] else val[ch]
print(ans)
