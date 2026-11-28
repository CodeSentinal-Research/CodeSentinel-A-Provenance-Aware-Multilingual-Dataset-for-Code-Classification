The Extended Euclidean Algorithm is a method for computing the greatest common divisor (gcd) of two numbers, as well as the coefficients of the linear relationship between them. It is used when finding the modular multiplicative inverse of A modulo M.

Here is the Python code for finding the modular multiplicative inverse of a given number A modulo M using the Extended Euclidean Algorithm.

def extended_euclid(a, m):
    if a == 0:
        return m, 0, 1
    else:
        gcd, x, y = extended_euclid(m % a, a)
        return gcd, y - (m // a) * x, x

def mod_inverse(a, m):
    gcd, x, y = extended_euclid(a, m)
    if gcd != 1:
        return -1
    else:
        return x % m

def main():
    a = int(input("Enter A: "))
    m = int(input("Enter M: "))
    print("Modular multiplicative inverse is: ", mod_inverse(a, m))

if __name__ == "__main__":
    main()

This code first defines a function `extended_euclid(a, m)` that implements the Extended Euclidean Algorithm. This function takes two parameters, `a` and `m`, and returns the gcd, x and y such that `ax + by = gcd(a, m)`.

Then, it defines a function `mod_inverse(a, m)` that computes the modular multiplicative inverse of `a` modulo `m` using the Extended Euclidean Algorithm. If the gcd of `a` and `m` is not 1, then the function returns -1. Otherwise, it returns the modular multiplicative inverse.

Finally, it defines a `main()` function that handles the input and prints the modular multiplicative inverse.

You can run this code with a Python interpreter. When you run it, you will be prompted to enter the values of A and M. After entering the values, the program will print the modular multiplicative inverse of A modulo M. If the modular multiplicative inverse does not exist, the program will print -1.