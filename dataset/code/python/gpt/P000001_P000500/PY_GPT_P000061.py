# problem title : Count Odd Digits
# Count digits with an odd numeric value.
digits = input().strip()
print(sum(int(ch) % 2 for ch in digits))
