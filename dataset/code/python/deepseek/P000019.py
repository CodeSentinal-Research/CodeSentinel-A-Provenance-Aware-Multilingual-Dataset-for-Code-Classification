Here is the Python code for the given problem:

def print_multiplication_table(n):
    if 1 <= n <= 20:
        for i in range(1, 11):
            print(f'{n} * {i} = {n*i}')
    else:
        print("Invalid input. Please enter a positive integer between 1 and 20.")

def main():
    n = int(input("Enter a positive integer between 1 and 20: "))
    print_multiplication_table(n)

if __name__ == "__main__":
    main()

In this code, we define a function `print_multiplication_table(n)` that prints the multiplication table of a given number up to 10. We check if the input `n` is in the range 1 to 20. If not, we print an error message. If `n` is in the range 1 to 20, we print the multiplication table using a loop from 1 to 10.

The `main()` function is the entry point of the program. It reads an integer input from the user, and calls the `print_multiplication_table(n)` function with this input.

Finally, if the program is run directly (i.e., if this code is the file containing the code and not imported as a module), it calls the `main()` function.