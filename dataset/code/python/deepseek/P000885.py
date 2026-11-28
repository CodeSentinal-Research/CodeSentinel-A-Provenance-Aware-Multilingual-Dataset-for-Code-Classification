Here is the Python code for the problem:

def is_armstrong(n):
    n_str = str(n)
    num_digits = len(n_str)

    sum_digits = sum(int(digit)**num_digits for digit in n_str)

    return sum_digits == n


def main():
    n = int(input("Enter a number: "))
    if is_armstrong(n):
        print("True")
    else:
        print("False")


if __name__ == "__main__":
    main()

In this code, `is_armstrong` is a function that checks if a given number `n` is an Armstrong number. It first converts `n` to a string to get the number of digits in `n`. It then calculates the sum of each digit raised to the power of `num_digits` and checks if this sum is equal to `n`.

In the `main` function, it reads a number from user input and checks if it is an Armstrong number. If it is, it prints `True`, otherwise it prints `False`.