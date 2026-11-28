Here is the Python code for the given problem:

def calculate_npr(n, r):
    if not isinstance(n, int) or not isinstance(r, int):
        raise TypeError("Both inputs should be integers.")
    if n < 0 or r < 0:
        raise ValueError("Both inputs should be non-negative.")
    if r > n:
        raise ValueError("r should not be greater than n.")

    result = 1
    for i in range(n, n - r, -1):
        result *= i
    return result


def main():
    try:
        n = int(input("Enter the value of n: "))
        r = int(input("Enter the value of r: "))
        print("nPr = ", calculate_npr(n, r))
    except ValueError as ve:
        print("Error: ", ve)
    except TypeError as te:
        print("Error: ", te)


if __name__ == "__main__":
    main()

In this code, we first check if the input is valid, then we calculate the permutation using a for loop in reverse order and finally return the result. We also have a main function that handles the input from the user and prints the result. If the input is not valid, it raises an error and the error message is printed.