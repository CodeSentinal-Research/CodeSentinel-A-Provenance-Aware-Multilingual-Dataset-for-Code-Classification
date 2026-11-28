Here is the Python code for the problem:

def is_divisible(a, b):
    if a % b == 0:
        print("Divisible")
    else:
        print("Not Divisible")

try:
    a = int(input("Enter a number: "))
    b = int(input("Enter another number: "))
    is_divisible(a, b)
except ValueError:
    print("Invalid input! Please enter valid numbers.")

This program first reads two integers from user input. It then checks if the first number is divisible by the second number. If the first number is divisible by the second number, it prints "Divisible", otherwise it prints "Not Divisible". If the input is not a number, it prints an error message and prompts for input again.