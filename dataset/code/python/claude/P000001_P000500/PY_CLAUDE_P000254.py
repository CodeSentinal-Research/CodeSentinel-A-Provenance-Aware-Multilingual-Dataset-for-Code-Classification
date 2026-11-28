
s=input().lower();vowels=set("aeiou");print(sum(1 for c in s if c.isalpha() and c not in vowels))
