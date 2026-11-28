# problem title : Check Whether Character is Alphabet
# isalpha() checks whether the character belongs to the alphabet.
c = input().strip()[0]
print("Alphabet" if c.isalpha() and c.isascii() else "Not Alphabet")
