Here is the Python code that generates all binary strings of length N using recursion and prints them in lexicographical order:

def generate_binary_strings(n):
    if n == 1:
        return ['0', '1']

    substrings = generate_binary_strings(n - 1)
    result = []
    for substring in substrings:
        result.extend(['0' + substring, '1' + substring])
    return result

def main():
    n = int(input("Enter the length of the binary string: "))
    if not (1 <= n <= 20):
        print("Invalid input! Please enter an integer between 1 and 20.")
        return

    binary_strings = generate_binary_strings(n)
    binary_strings.sort()

    for binary_string in binary_strings:
        print(binary_string)

if __name__ == "__main__":
    main()

This program first gets the length of the binary string from the user. It then calls the `generate_binary_strings` function with this length, and prints the generated binary strings in lexicographical order.

The `generate_binary_strings` function is a recursive function that generates all binary strings of a given length. It does this by generating all binary strings of the (n-1)th length, and then for each of these strings, it adds a '0' to the beginning and a '1' to the end to create new strings, and adds these to the list of results.

In the `main` function, we first check if the user has entered a valid length. If not, we print an error message and return from the function.

We then call the `generate_binary_strings` function with the length of the binary string, and print all the generated binary strings in lexicographical order.