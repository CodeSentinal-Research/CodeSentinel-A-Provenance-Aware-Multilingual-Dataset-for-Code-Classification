Here is the Python code for the problem:

def decimal_to_binary(n):
    if n >= 2**63 or n < 0:
        raise ValueError("Input should be a non-negative integer less than 2^63")

    binary = ''
    if n == 0:
        return '0'

    while n > 0:
        binary = str(n % 2) + binary
        n = n // 2
    return binary

def main():
    try:
        n = int(input("Enter a non-negative integer: "))
        print(decimal_to_binary(n))
    except ValueError:
        print("Invalid input. Please enter a non-negative integer less than 2^63.")

if __name__ == "__main__":
    main()

In this code, the `decimal_to_binary` function takes an integer `n` as input and returns its binary representation. This function uses a while loop to continuously divide `n` by 2 and prepend the remainder to the binary string, effectively reversing the binary digits. If `n` is 0, it returns '0'.

The `main` function is where the input and output are handled. It first prompts the user to enter a non-negative integer, which is stored in `n`. If `n` is less than 0 or greater than 2^63 - 1, it raises a `ValueError`. Otherwise, it calls the `decimal_to_binary` function to convert `n` to binary and prints the result.