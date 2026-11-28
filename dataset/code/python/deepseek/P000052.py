Here is the Python code:

def convert_upper_to_lower(c):
    return chr(ord(c) + 32)

def main():
    c = input("Enter an uppercase letter: ")
    if not c.isupper():
        print("Input is not an uppercase letter.")
        return
    print(convert_upper_to_lower(c))

if __name__ == "__main__":
    main()

In this code, the `ord()` function is used to get the ASCII value of a character, and the `chr()` function is used to get the character corresponding to a given ASCII value. The ASCII value of an uppercase letter is 32 added to it to get the ASCII value of its corresponding lowercase letter. The `isupper()` function is used to check if a character is an uppercase letter.