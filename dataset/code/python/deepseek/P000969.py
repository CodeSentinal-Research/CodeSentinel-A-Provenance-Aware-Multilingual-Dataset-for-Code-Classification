Here is a Python solution for the problem using a recursive approach.

def fibonacci(n):
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)

This code defines a function `fibonacci(n)` that computes the nth Fibonacci number using the recurrence relation. The base cases are 0 and 1, respectively, and the recursion case is the sum of the previous two Fibonacci numbers.

To handle the input, we can use the built-in `input()` function in Python. We then use `int()` to convert the user input to an integer and pass it to the `fibonacci(n)` function.

Here is the main function:

def main():
    n = int(input("Enter a number: "))
    print("The", n, "th Fibonacci number is:", fibonacci(n))

if __name__ == "__main__":
    main()

In this main function, the user is prompted to enter a number, which is converted to an integer using `int()`. The function `fibonacci(n)` is then called with this number as the argument, and the result is printed.