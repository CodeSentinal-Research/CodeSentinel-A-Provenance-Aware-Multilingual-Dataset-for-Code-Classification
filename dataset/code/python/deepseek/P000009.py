def max_of_two_numbers(a, b):
    if a > b:
        return a
    else:
        return b

def main():
    a = int(input("Enter first number: "))
    b = int(input("Enter second number: "))
    print("The maximum number is: ", max_of_two_numbers(a, b))

if __name__ == "__main__":
    main()