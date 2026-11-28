Here is a simple Python code that counts the consonants in a string:

def count_consonants(s):
    consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ"
    count = 0
    for char in s:
        if char in consonants:
            count += 1
    return count

s = input("Enter a string: ")
print("Number of consonants: ", count_consonants(s))

In this code, we define a function `count_consonants` that takes a string `s` as input. We define a string of consonants (both lower and upper case), and initialize a counter `count` to 0. We then iterate over each character in the string `s`. If the character is in the consonants string, we increment the counter. Finally, we return the count.

The input handling part reads a line from the user, calls the `count_consonants` function with the user's input, and prints the result.