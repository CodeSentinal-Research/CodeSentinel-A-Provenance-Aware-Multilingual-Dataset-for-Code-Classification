Here is the Python code:

import math

def power(A, N):
    return pow(A, N, N)

def main():
    A = int(input("Enter A: "))
    N = int(input("Enter N: "))

    print(power(A, N))

if __name__ == "__main__":
    main()

In this code, the `power` function computes `A` raised to the power of `N` modulo `N`. The `pow` function is used to compute the power in this way. The modulo operator (`%`) is also used to ensure that the result is within the range of `N`.

The `main` function is the entry point of the program. It prompts the user for `A` and `N`, calls `power` with these values, and prints the result.