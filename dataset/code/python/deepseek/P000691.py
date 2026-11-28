Here is the Python code for the problem:

def gcd_recursive(a, b):
    if b == 0:
        return a
    else:
        return gcd_recursive(b, a % b)

def main():
    a = int(input("Enter the first number: "))
    b = int(input("Enter the second number: "))
    print("The greatest common divisor of", a, "and", b, "is", gcd_recursive(a, b))

if __name__ == "__main__":
    main()

This code defines a function `gcd_recursive` that uses recursion to calculate the greatest common divisor of two numbers. The `main` function is used to handle user input and print the result of `gcd_recursive`.

The `input` function is used to get user input for the numbers to calculate the GCD of. The `print` function is used to print the result of `gcd_recursive`.

Please note that the provided code assumes that the inputs are valid integers. If there are possible cases that the inputs might not be valid integers (e.g., negative numbers, or floats), you should add some error handling code to ensure the inputs are valid.