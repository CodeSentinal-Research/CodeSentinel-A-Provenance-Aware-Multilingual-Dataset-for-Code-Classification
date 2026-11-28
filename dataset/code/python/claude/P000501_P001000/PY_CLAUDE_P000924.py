
n=int(input())
print(bin(n)[2:] if n>=0 else '-'+bin(n)[3:])
