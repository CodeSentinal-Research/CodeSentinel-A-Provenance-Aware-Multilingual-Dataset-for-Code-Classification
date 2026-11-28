
n=int(input())
res=''
while n:
    n-=1;res=chr(ord('A')+n%26)+res;n//=26
print(res)
