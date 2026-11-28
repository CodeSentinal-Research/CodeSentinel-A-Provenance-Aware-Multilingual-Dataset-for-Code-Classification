# problem title : Excel Sheet Column Number
# Accumulate letters as a base-26 number where A represents one.
s=input().strip(); n=0
for ch in s:n=n*26+ord(ch)-64
print(n)
