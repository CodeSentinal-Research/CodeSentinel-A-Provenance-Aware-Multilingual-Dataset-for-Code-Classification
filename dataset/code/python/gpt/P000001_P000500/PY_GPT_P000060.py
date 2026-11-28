# problem title : Count Even Digits
# Count digits whose value is divisible by two.
digits = input().strip()
print(sum(int(ch) % 2 == 0 for ch in digits))
