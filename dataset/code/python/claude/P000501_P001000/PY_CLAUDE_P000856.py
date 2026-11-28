
n=int(input())
print(len(bin(n))-len(bin(n).rstrip('0')) if n>0 else 0)
