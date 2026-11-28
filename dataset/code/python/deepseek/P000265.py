Here's the Python code:

def remove_duplicate(s):
    result = []
    for char in s:
        if char not in result:
            result.append(char)
    return ''.join(result)

def main():
    s = input("Enter a string: ")
    print(remove_duplicate(s))

if __name__ == "__main__":
    main()

In this code, we define a function `remove_duplicate(s)` which takes a string `s` as an input and returns a new string where all duplicate characters are removed while preserving the original order.

The `main()` function is the entry point of the program. It takes the user input and calls the `remove_duplicate(s)` function to process the input string.

The `if __name__ == "__main__":` block is used to call the `main()` function when the script is run directly.