# problem title : Count Consonants in a String
# Alphabetic characters that are not vowels are consonants.
s=input(); print(sum(ch.isalpha() and ch.lower() not in "aeiou" for ch in s))
