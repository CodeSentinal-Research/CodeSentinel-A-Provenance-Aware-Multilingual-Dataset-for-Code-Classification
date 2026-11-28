
n=int(input())
bits=n.bit_length();mask=(1<<bits)-1
print(n^mask)
