Here is the Python code:

def find_character(s, c):
    return s.find(c)

def main():
    s = input("Enter a string: ")
    c = input("Enter a character to search: ")
    result = find_character(s, c)
    if result != -1:
        print("First occurrence of character is at index:", result)
    else:
        print("Character not found in string")

if __name__ == "__main__":
    main()
In this code, the `find_character` function uses the built-in `find` method of Python string objects to find the first occurrence of a given character in the string. If the character is not found, it returns -1. The `main` function handles the user input and output.