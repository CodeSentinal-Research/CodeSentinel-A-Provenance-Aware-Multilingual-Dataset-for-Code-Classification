Here is the Python code for the problem:

def sum_of_natural_numbers(n):
    if n == 0:
        return 0
    else:
        return n + sum_of_natural_numbers(n - 1)

n = int(input("Enter a number: "))
print("Sum of first", n, "natural numbers is", sum_of_natural_numbers(n))

In this code, the function `sum_of_natural_numbers(n)` is defined, which recursively adds up the first `n` natural numbers. The recursion is done by calling the function itself with the argument `n - 1` until `n` becomes `0`, at which point the recursion stops.

The main part of the program handles the input and prints the result of the sum_of_natural_numbers function.