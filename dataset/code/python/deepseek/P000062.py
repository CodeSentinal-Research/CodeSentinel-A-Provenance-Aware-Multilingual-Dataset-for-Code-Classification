Here is the Python code for the given problem:

import math

def is_strong(n):
    sum_fact = 0
    temp = n
    while temp > 0:
        digit = temp % 10
        sum_fact += math.factorial(digit)
        temp //= 10
    return n == sum_fact

def main():
    n = int(input("Enter a positive integer: "))
    while n < 1 or n > 100000:
        print("Input should be between 1 and 100000")
        n = int(input("Enter a positive integer: "))
    if is_strong(n):
        print("Strong")
    else:
        print("Not Strong")

if __name__ == '__main__':
    main()

This program first checks if the given input is a strong number using a while loop to continuously prompt the user until a valid input is provided.

The `is_strong` function calculates the factorial of each digit in the number and then checks if it equals the original number.

In the `main` function, the program gets the input, checks if it's a strong number using the `is_strong` function, and then prints the result. If the input is not a strong number, it prints "Not Strong".