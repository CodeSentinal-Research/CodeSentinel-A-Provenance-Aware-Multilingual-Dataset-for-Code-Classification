# problem title : Find the Difference
# XOR of all character codes cancels equal characters and leaves the extra one.
a=input();b=input(); x=0
for ch in a+b:x^=ord(ch)
print(chr(x))
