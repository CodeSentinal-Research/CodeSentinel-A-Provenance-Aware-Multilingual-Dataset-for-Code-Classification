
n=int(input())
print(int(bin(n)[2:].zfill(32)[::-1],2))
