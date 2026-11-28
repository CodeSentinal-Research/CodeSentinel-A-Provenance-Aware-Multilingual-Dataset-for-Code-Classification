def find_max(a, b, c):
    return max(a, b, c)

def main():
    a = int(input("Enter the first number: "))
    b = int(input("Enter the second number: "))
    c = int(input("Enter the third number: "))

    print("The maximum of the three numbers is: ", find_max(a, b, c))

if __name__ == "__main__":
    main()