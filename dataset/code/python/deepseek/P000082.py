Here is the Python code:

def is_special_symbol(c):
    special_symbols = ['@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '<', '=', '>', '?', '~']
    if c in special_symbols:
        print("Special Symbol")
    else:
        print("Not Special Symbol")

def main():
    c = input("Enter a character: ")
    is_special_symbol(c)

if __name__ == "__main__":
    main()

The `is_special_symbol` function checks if a given character is in the list of special symbols. If it is, it prints "Special Symbol"; otherwise, it prints "Not Special Symbol".

The `main` function reads a character from the user and passes it to `is_special_symbol`.

The `main` function is the entry point of the program. When the program is run, it first prints a message asking for input, then it takes input from the user and prints the result.

Please note that the special symbols used in this program are the ones used in Unix/Linux systems, as they are the characters used in some commands and in some environments. They are not the same as in Windows, where these characters are used to denote other types of input.