Here's the Python code:

def sum_of_series(n):
    return n * (n + 1)

def main():
    n = int(input("Enter a positive integer: "))
    print("The sum of the first", n, "even numbers is", sum_of_series(n))

if __name__ == "__main__":
    main()

In this code, `sum_of_series` function calculates the sum of series 2+4+6+...+N, where N is the input number. The `main` function gets the input number from the user, calls `sum_of_series` function to calculate the sum, and prints the result.

The `if __name__ == "__main__":` part is used to call the `main` function when the script is run directly. If the script is imported as a module, `main` function won't be called.