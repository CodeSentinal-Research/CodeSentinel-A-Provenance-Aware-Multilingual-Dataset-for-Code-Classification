Here is the Python code for the problem:

def reverse_string(s):
    if len(s) == 0:
        return s
    else:
        return reverse_string(s[1:]) + s[0]

def main():
    s = input("Enter a string: ")
    print("Reversed string: ", reverse_string(s))

if __name__ == "__main__":
    main()

This code defines a function `reverse_string` that takes a string `s` as an argument. If the length of the string is 0, it returns the string. Otherwise, it calls itself with the string after the first character (`s[1:]`), and concatenates the first character (`s[0]`) to the result. This process continues until the string is empty, at which point the recursion ends and the function returns the reversed string.

The main function takes a string as input, calls `reverse_string` with this string, and prints the result.

The `if __name__ == "__main__":` line is used to call the main function when the script is run directly. If this line is omitted, the main function will not be called when the script is imported as a module.