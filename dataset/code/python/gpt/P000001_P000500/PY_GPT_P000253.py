# problem title : Count Vowels in a String
# Count only alphabetic vowel characters.
s=input(); print(sum(ch.lower() in "aeiou" for ch in s if ch.isalpha()))
