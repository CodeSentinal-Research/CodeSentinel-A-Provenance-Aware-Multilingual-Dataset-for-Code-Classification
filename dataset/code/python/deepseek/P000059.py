Here is the Python code:

def find_product_of_digits(n):
    product = 1
    while n > 0:
        digit = n % 10
        product *= digit
        n //= 10
    return product

def main():
    n = int(input("Enter a non-negative integer: "))
    if n >= 0:
        print("The product of its digits is:", find_product_of_digits(n))
    else:
        print("Invalid input. Please enter a non-negative integer.")

if __name__ == "__main__":
    main()

In this code, we first define a function `find_product_of_digits(n)` that calculates the product of the digits of `n`. In this function, we use a while loop to repeatedly divide `n` by 10, taking the remainder (which is the current digit of `n`) and multiply it into the product, then integer divide `n` by 10 (which removes the last digit of `n`).

The `main()` function handles the user input. It first prompts the user to enter a non-negative integer. If the input is valid (i.e., a non-negative integer), it calls `find_product_of_digits(n)` to calculate and print the product of the digits of `n`. If the input is not valid, it prints an error message.

Finally, if this script is run as the main program (i.e., if it is the first line of code that is run), it calls the `main()` function.