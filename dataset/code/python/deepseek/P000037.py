Here is the Python code for the problem:

def binary_to_decimal(binary_string):
    binary_int = int(binary_string, 2)
    return binary_int

def main():
    binary_string = input("Enter a binary string (1s and 0s, up to 30 chars long): ")
    if len(binary_string) > 30:
        print("Invalid input. The binary string should be up to 30 characters long.")
        return
    decimal_int = binary_to_decimal(binary_string)
    print("The decimal equivalent of the binary string is: ", decimal_int)

if __name__ == "__main__":
    main()

This program first takes a binary string as input from the user. It then checks if the length of the string is more than 30. If it is, it prints an error message and returns. If it's not, it calls the `binary_to_decimal` function, which converts the binary string to an integer and prints the result.