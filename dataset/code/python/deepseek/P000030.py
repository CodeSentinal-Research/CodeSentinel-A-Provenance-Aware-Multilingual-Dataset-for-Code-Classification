def lcm(a, b):
    if a > b:
        greater = a
    else:
        greater = b

    while True:
        if greater % a == 0 and greater % b == 0:
            lcm = greater
            break
        greater += 1

    return lcm


def main():
    a = int(input("Enter first number: "))
    b = int(input("Enter second number: "))

    if a > 0 and b > 0:
        print(f"The LCM of {a} and {b} is {lcm(a, b)}")
    else:
        print("Input must be positive integers.")


if __name__ == "__main__":
    main()