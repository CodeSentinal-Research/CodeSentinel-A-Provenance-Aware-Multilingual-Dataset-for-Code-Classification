
num=input().strip();a,b=int(input()),int(input())
dec=int(num,a)
if dec==0: print('0');exit()
digits=[]
while dec: digits.append('0123456789ABCDEF'[dec%b]);dec//=b
print(''.join(reversed(digits)))
