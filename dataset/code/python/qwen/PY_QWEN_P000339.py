s = input().strip()
half = len(s) // 2
vowels = set("aeiouAEIOU")
c1 = sum(1 for c in s[:half] if c in vowels)
c2 = sum(1 for c in s[half:] if c in vowels)
print("Yes" if c1 == c2 else "No")
