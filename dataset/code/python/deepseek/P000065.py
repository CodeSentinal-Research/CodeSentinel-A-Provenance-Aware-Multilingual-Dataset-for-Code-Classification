def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)

def lcm(a, b):
    return (a / gcd(a, b)) * b

def lcm_of_three_numbers(a, b, c):
    return lcm(lcm(a, b), c)

def main():
    a = int(input("Enter the first number: "))
    b = int(input("Enter the second number: "))
    c = int(input("Enter the third number: "))

    print("The LCM of", a, ",", b, "and", c, "is", lcm_of_three_numbers(a, b, c))

if __name__ == "__main__":
    main()