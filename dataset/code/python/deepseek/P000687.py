Here is the Python code for the given problem:

def sum_of_digits(n):
    if n == 0:
        return 0
    else:
        return n%10 + sum_of_digits(n//10)

n = int(input("Enter a non-negative integer: "))
while n<0 or n>10**18:
    print("Invalid input. Please enter a non-negative integer within the constraints.")
    n = int(input("Enter a non-negative integer: "))
print("The sum of the digits is:", sum_of_digits(n))

The function sum_of_digits(n) recursively calculates the sum of digits of a given number n. If n is 0, the function returns 0. Otherwise, it calculates the sum of the last digit (n%10) and the sum of the rest of the digits (n//10).

The input handling part of the code is necessary to ensure that the input number is non-negative and within the constraints.