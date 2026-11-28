s = input().strip()
print("".join(c for c in s if not c.isalpha() or c.lower() in "aeiou"))
