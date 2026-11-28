Here's the python code for finding the least common multiple of two numbers.

def gcd(a, b):
    if b==0:
        return a
    else:
        return gcd(b, a % b)

def lcm(a, b):
    return (a * b) // gcd(a, b)

def main():
    A = int(input("Enter the first number: "))
    B = int(input("Enter the second number: "))
    print("The LCM is:", lcm(A, B))

if __name__ == "__main__":
    main()

This code first defines a function to calculate the greatest common divisor (gcd) using the Euclidean algorithm. Then, it uses this gcd to calculate the least common multiple (lcm) by dividing the product of the two numbers by their gcd.

In the main function, we first get the two numbers from the user, then print out the lcm of these two numbers.

Keep in mind that this code can still fail for very large inputs due to integer overflow. A better approach would be to use a library that supports arbitrary-precision arithmetic, or to use the math.gcd() function directly.