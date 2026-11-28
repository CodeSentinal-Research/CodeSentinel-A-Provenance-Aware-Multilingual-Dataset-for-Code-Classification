s = input().strip()
print(sum(1 for c in s if c.isalpha() and c.lower() not in "aeiou"))
