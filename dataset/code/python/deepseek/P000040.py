Here's the Python code:

def print_ascii_characters():
    for i in range(32, 127):
        print(chr(i), i)

print_ascii_characters()

In this code, the `print_ascii_characters` function uses a for loop to iterate over the range of ASCII characters from 32 to 126. For each character, it prints the character followed by its ASCII value.