# problem title : Find Two Elements with Odd Occurrence
# The XOR of all values leaves the XOR of the two odd-occurring values.
n = int(input()); a = list(map(int, input().split()))[:n]
total_xor = 0
for x in a: total_xor ^= x
bit = total_xor & -total_xor
first = second = 0
for x in a:
    if x & bit: first ^= x
    else: second ^= x
print(*sorted((first, second)))
