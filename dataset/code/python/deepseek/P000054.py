Sure, here's the code:

def print_alphabet():
    for i in range(ord('A'), ord('Z') + 1):
        print(chr(i), end=' ')

print_alphabet()

In this code, we are using the `ord` function to get the ASCII value of 'A' and 'Z'. Then we are using the `chr` function to convert the ASCII value back into a character. The `range` function is used to generate all ASCII values between 'A' and 'Z' inclusive. The `end=' '` is used to print the characters without a newline.