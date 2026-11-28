# problem title : String to Integer (atoi)
# Parse optional sign and digits manually, stopping at the first non-digit.
s=input().strip(); i=0
while i<len(s) and s[i]==' ':i+=1
sign=1
if i<len(s) and s[i] in '+-': sign=-1 if s[i]=='-' else 1; i+=1
num=0
while i<len(s) and s[i].isdigit(): num=num*10+int(s[i]); i+=1
num*=sign
print(max(-2**31,min(2**31-1,num)))
