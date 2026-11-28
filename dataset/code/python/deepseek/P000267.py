Here is a Python solution using the in-built `replace()` method:

def replace_char(s, old, new):
    return s.replace(old, new)

s = input("Enter a string: ")
old = input("Enter the character to replace: ")
new = input("Enter the new character: ")
print(replace_char(s, old, new))

This code will take as input the string, the character to be replaced and the new character. The `replace_char` function then uses the `replace()` method to replace all occurrences of the old character in the string with the new character. The final string is then printed to the console.