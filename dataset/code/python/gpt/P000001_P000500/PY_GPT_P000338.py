# problem title : Check if Two String Arrays are Equivalent
# Concatenating each array into one string makes equality independent of chunk boundaries.
a=input().split();b=input().split();print("Yes" if ''.join(a)==''.join(b) else "No")
