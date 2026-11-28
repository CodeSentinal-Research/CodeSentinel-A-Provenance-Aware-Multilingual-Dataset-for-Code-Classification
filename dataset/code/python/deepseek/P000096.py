Here is the Python code:

def is_spy(n):
    product = 1
    sum_digits = 0
    for digit in str(n):
        sum_digits += int(digit)
        product *= int(digit)
    if sum_digits == product:
        return 'Spy'
    else:
        return 'Not Spy'

def main():
    n = int(input("Enter a positive integer: "))
    while not (1 <= n <= 10**6):
        print("Invalid input. Please enter a positive integer between 1 and 10^6.")
        n = int(input("Enter a positive integer: "))
    print(is_spy(n))

if __name__ == "__main__":
    main()

In this program, the function `is_spy(n)` checks whether a given number `n` is a spy number. It first initializes `product` to 1 and `sum_digits` to 0. Then, it converts `n` into a string and iterates over each digit. It adds the digit to `sum_digits` and multiplies it with `product`. After all digits have been processed, it checks if `sum_digits` is equal to `product`. If they are equal, the number is a spy number; otherwise, it's not.

The `main()` function takes the user input and checks whether it's valid. It keeps asking for input until a valid number is entered. It then prints the result of calling `is_spy(n)` with `n`.