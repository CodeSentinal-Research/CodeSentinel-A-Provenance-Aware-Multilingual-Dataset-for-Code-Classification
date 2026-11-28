Here is the Python code for your problem:

def print_fibonacci_series(n):
    a = 0
    b = 1
    for _ in range(n):
        print(a, end=' ')
        a, b = b, a + b

n = int(input("Enter a positive integer: "))
print_fibonacci_series(n)

In this program, we define a function `print_fibonacci_series(n)` that takes an integer `n` as input and prints the first `n` numbers of the Fibonacci series. 

The Fibonacci series is a sequence of numbers in which each number is the sum of the two preceding ones, usually starting with 0 and 1. The sequence looks like this: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, and so forth.

The function uses two variables `a` and `b` to store the last two numbers of the series, and then it updates them in a loop `n` times. In each iteration, it prints the current number and updates `a` and `b` for the next iteration.

The input handling is done in the main function, where it asks the user to enter a positive integer `n`. Then it calls the `print_fibonacci_series(n)` function with `n` as the argument.