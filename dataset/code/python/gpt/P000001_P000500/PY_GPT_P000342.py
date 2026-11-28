# problem title : Replace All Digits with Characters
# Each digit is replaced by the character located that many positions before it.
s=input();out=[]
for i,ch in enumerate(s): out.append(chr(ord(s[i-1])+int(ch)) if ch.isdigit() and i else ch)
print(''.join(out))
