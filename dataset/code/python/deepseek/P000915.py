Here is the Python code for the problem:

def count_handshakes(n):
    if n == 1:
        return 0
    elif n == 2:
        return 1
    else:
        return (n - 1) + count_handshakes(n - 1)

def main():
    n = int(input("Enter the number of people sitting around the table: "))
    while n < 1 or n > 500:
        print("Invalid input. Please enter a number between 1 and 500.")
        n = int(input("Enter the number of people sitting around the table: "))
    print("Number of valid handshake arrangements: ", count_handshakes(n))

if __name__ == "__main__":
    main()
In this code, the function `count_handshakes(n)` is a recursive function that calculates the number of possible handshake arrangements for `n` people sitting around the table. The base cases for `n = 1` and `n = 2` are handled separately. For `n > 2`, the function calls itself with `n - 1` as the argument, adding the number of handshakes made between the `n - 1` people and the table.

The `main()` function handles the input and error checking. It asks the user for the number of people sitting around the table, and keeps asking until a valid number is entered. It then calls `count_handshakes(n)` to get the number of valid handshake arrangements for `n` people.

This code assumes that the user will enter a positive integer less than or equal to 500.