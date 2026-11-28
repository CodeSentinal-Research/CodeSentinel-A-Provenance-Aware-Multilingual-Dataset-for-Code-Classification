def swap_numbers(a, b):
    print("Before swapping: a =", a, ", b =", b)

    a, b = b, a

    print("After swapping: a =", a, ", b =", b)


def main():
    a = int(input("Enter the first number: "))
    b = int(input("Enter the second number: "))

    swap_numbers(a, b)


if __name__ == "__main__":
    main()