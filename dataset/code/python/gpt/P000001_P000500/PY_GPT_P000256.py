# problem title : Remove All Consonants
# Keep vowels and non-letter characters while removing alphabetic consonants.
s=input(); print(''.join(ch for ch in s if not(ch.isalpha() and ch.lower() not in "aeiou")))
