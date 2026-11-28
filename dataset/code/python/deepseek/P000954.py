Here is the Python solution for the given problem:

def extended_euclidean(a, b):
    if a == 0:
        return b, 0, a
    else:
        gcd, x, y = extended_euclidean(b % a, a)
        return gcd, y - (b // a) * x, x

def main():
    a = int(input("Enter the first integer: "))
    b = int(input("Enter the second integer: "))
    gcd, x, y = extended_euclidean(a, b)
    print(f"The values of X and Y are: {x}, {y}")
    print(f"The greatest common divisor of {a} and {b} is: {gcd}")

if __name__ == "__main__":
    main()

This Python program uses the Extended Euclidean Algorithm to find the values of X and Y such that AX + BY = gcd(A, B). The program prompts the user for input A and B, then calls the extended_euclidean function to find the gcd and the values of X and Y. The result is then printed out.