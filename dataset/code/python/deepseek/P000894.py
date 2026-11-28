Here is the Python code for the Greatest Common Divisor (GCD) of two numbers using Euclidean algorithm:

def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

try:
    a = int(input("Enter first number: "))
    b = int(input("Enter second number: "))
    print("The GCD of", a, "and", b, "is", gcd(a, b))
except ValueError:
    print("Invalid input! Please enter integer values only.")

In this code, the function gcd(a, b) calculates the GCD of a and b using the Euclidean algorithm. The while loop continues until b is 0, at which point a is the GCD. The input handling section captures the inputs for a and b, and checks if they are valid integers. If not, it prints an error message.