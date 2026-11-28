Here is the Python code:

def linear_recurrence(A, B, F0, F1, N):
    Fn = F0

    for i in range(2, N + 1):
        Fn = A * Fn + B * (Fn - 1)

    return Fn


def main():
    A = int(input("Enter A: "))
    B = int(input("Enter B: "))
    F0 = int(input("Enter F0: "))
    F1 = int(input("Enter F1: "))
    N = int(input("Enter N: "))

    if not (0 <= N <= 10**6):
        print("Invalid N. It should be in the range 0 <= N <= 10^6.")
        return

    Fn = linear_recurrence(A, B, F0, F1, N)
    print("Fn: ", Fn)


main()

This code defines a function `linear_recurrence` that computes the Fn value of the given recurrence. The function takes the coefficients A, B, initial values F0 and F1, and the number of terms N as arguments. It first initializes Fn to F0, and then computes Fn for each term from 2 to N.

The main function, `main`, handles the user inputs for A, B, F0, F1, and N. It also validates the inputs to make sure they are within the specified constraints. If the inputs are valid, the `linear_recurrence` function is called to compute and print the Fn value. If the inputs are not valid, an error message is printed.