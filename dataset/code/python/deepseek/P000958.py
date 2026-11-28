Sure, here is a Python code for the given problem:

def find_bezout_solution(a, b):
    x, y = 1, b
    while True:
        gcd = a % b
        if gcd == 0:
            return x, y
        a, b = b, gcd
        x, y = y - (a // b) * x, x

def main():
    a = int(input("Enter a number: "))
    b = int(input("Enter another number: "))
    x, y = find_bezout_solution(a, b)
    print("The smallest positive integer X is: ", x)
    print("The smallest positive integer Y is: ", y)

if __name__ == "__main__":
    main()

This code first asks for two integers from the user. It then calls the `find_bezout_solution` function which calculates the smallest positive integer X and Y that satisfy Bézout's Identity for the given A and B. The function uses the Euclidean algorithm to find the greatest common divisor of A and B, which is then used to find X and Y.

The `main` function is the entry point of the program, and it calls the `find_bezout_solution` function to find the smallest positive integers X and Y. It then prints the values of X and Y.

The `if __name__ == "__main__":` block ensures that the `main` function is only called when the script is run directly, not when it is imported as a module.

Please note that this code only works for small inputs. For larger inputs, you might need to use a more sophisticated algorithm or library that supports Bézout's Identity.