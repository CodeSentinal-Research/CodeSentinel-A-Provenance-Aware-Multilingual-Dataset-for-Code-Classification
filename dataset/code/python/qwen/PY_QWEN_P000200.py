n = int(input())
arr = list(map(int, input().split()))
xor_all = 0
for x in arr:
    xor_all ^= x
rightmost_set_bit = xor_all & -xor_all
num1, num2 = 0, 0
for x in arr:
    if x & rightmost_set_bit:
        num1 ^= x
    else:
        num2 ^= x
print(min(num1, num2), max(num1, num2))
