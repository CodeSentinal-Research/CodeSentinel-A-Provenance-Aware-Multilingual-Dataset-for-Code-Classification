# problem title : Excel Sheet Column Title
# Excel columns are base-26 with digits 1 through 26 rather than 0 through 25.
n=int(input()); out=''
while n: n,rem=divmod(n-1,26); out=chr(65+rem)+out
print(out)
