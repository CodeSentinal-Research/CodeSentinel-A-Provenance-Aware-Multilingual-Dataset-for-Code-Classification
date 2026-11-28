Here is the Python code that solves the problem:

def broken_calculator(X, Y):
    count = 0
    while Y != X:
        if Y % 2 == 0:
            Y //= 2
        else:
            Y -= 1
        count += 1
    return count

def main():
    X, Y = map(int, input().split())
    print(broken_calculator(X, Y))

if __name__ == "__main__":
    main()
This code defines a function `broken_calculator` that takes two integers as input and calculates the minimum number of operations to reach the given value `Y` from `X`. The function uses a while loop to repeatedly divide `Y` by 2 if it's even and subtract 1 if it's odd, until `Y` equals `X`. The function also keeps track of the number of operations required.

The `main` function reads the input values `X` and `Y` and calls the `broken_calculator` function to print the minimum number of operations.

The input and output are handled in the `main` function, with the input read from `stdin`.