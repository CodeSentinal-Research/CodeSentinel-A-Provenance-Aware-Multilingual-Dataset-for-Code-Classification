def find_largest(a, b, c):
    if a > b:
        if a > c:
            return a
        else:
            return c
    else:
        if b > c:
            return b
        else:
            return c

def main():
    a = int(input("Enter the first number: "))
    b = int(input("Enter the second number: "))
    c = int(input("Enter the third number: "))
    largest = find_largest(a, b, c)
    print("The largest number is:", largest)

if __name__ == "__main__":
    main()