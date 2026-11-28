# problem title : Find the Element with Odd Occurrence
# XOR cancels every value occurring an even number of times.
n = int(input()); a = list(map(int, input().split()))[:n]
odd = 0
for x in a: odd ^= x
print(odd)
