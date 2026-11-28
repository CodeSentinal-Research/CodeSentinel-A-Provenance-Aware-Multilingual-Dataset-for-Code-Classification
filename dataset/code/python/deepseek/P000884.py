Here is the python code for the given problem:

def digital_root(n):
    def sum_of_digits(n):
        if n < 10:
            return n
        else:
            return sum_of_digits(sum(int(digit) for digit in str(n)))

    return sum_of_digits(n)


def main():
    n = int(input("Enter a non-negative integer: "))
    print("The digital root is:", digital_root(n))


if __name__ == '__main__':
    main()

This code defines a function called `digital_root` which takes an integer `n` as input and returns the digital root of `n`. It uses a helper function `sum_of_digits` to recursively sum the digits of `n` until it is a single digit number.

The `main` function takes input from the user and calls `digital_root` with that input.

This is a basic approach and may not be the most efficient or reliable for large numbers due to the recursive nature of the algorithm.