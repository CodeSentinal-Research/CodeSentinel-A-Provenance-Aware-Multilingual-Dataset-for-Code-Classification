Here is the Python code:

def print_numbers(n):
    if n > 0:
        print(n, end=' ')
        print_numbers(n-1)

n = int(input())
print_numbers(n)

In this code, we define a function `print_numbers` that takes an integer `n` as input. If `n` is greater than 0, we print the current number and then recursively call `print_numbers` with the argument `n-1`. This process is repeated until `n` is less than or equal to 0. 

The `end=' '` in the `print` function is used to ensure that the numbers are printed on the same line separated by a space.

The `input()` function is used to read the input for the integer `n`.

You can run this code in any Python environment. When you run it, you can input any integer, and it will print all numbers from that integer down to 1.