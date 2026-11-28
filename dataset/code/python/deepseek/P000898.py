Here is a Python solution for the problem using the math.gcd function to find the greatest common divisor (GCD) and the divmod function to get the reduced numerator and denominator.

import math

def reduce_fraction(numerator, denominator):
    gcd = math.gcd(numerator, denominator)
    reduced_numerator = numerator // gcd
    reduced_denominator = denominator // gcd
    return (reduced_numerator, reduced_denominator)

def main():
    while True:
        try:
            numerator = int(input("Enter the numerator: "))
            denominator = int(input("Enter the denominator: "))
            if not (1 <= numerator <= denominator <= (10**18)):
                print("Please enter valid inputs.")
            else:
                reduced_numerator, reduced_denominator = reduce_fraction(numerator, denominator)
                print(f"Reduced fraction: {reduced_numerator}/{reduced_denominator}")
                break
        except ValueError:
            print("Invalid input. Please enter integer values.")

if __name__ == "__main__":
    main()

This program first asks for the numerator and denominator from the user. It then checks if the inputs are valid (numerator and denominator are integers and within the constraints). If the inputs are valid, the program calls the reduce_fraction function to reduce the fraction to its lowest terms and prints the result. If the inputs are not valid, it prints an error message and asks for the inputs again.