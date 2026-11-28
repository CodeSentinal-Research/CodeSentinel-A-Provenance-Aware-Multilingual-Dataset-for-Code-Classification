# problem title : Remove All Vowels
# Filter out every vowel while preserving all other characters.
s=input(); print(''.join(ch for ch in s if ch.lower() not in "aeiou"))
