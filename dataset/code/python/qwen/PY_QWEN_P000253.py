s = input().strip()
print(sum(1 for c in s if c.lower() in "aeiou"))
