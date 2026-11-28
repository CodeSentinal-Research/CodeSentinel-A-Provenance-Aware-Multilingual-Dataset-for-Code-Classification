Here is a Python solution that uses a regular expression (regex) to validate the input.

import re

def is_valid_number(s):
    match = re.match('^-?\d+(\.\d+)?$', s)
    if match:
        print('Valid')
    else:
        print('Invalid')

def main():
    s = input("Enter a string: ")
    is_valid_number(s)

if __name__ == "__main__":
    main()

This code defines a function `is_valid_number(s)` that uses a regex to match a string that represents a valid number. If the input string matches the regex, the function prints "Valid", otherwise it prints "Invalid".

The `main()` function handles the input and calls the `is_valid_number()` function.

The `if __name__ == "__main__":` part ensures that the `main()` function is only called when the script is run directly, not when it's imported as a module.