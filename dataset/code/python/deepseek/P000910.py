Sure, here is a Python code that calculates permutations using the formula nPr = n! / (n - r)!. The function uses the math module's factorial function to calculate factorials, and the math module's comb function to calculate combinations.

import math

def compute_permutations(n, r):
    return math.factorial(n) / math.factorial(n - r)

def main():
    n = int(input("Enter the value of n: "))
    r = int(input("Enter the value of r: "))
    print("The value of nPr is: ", compute_permutations(n, r))

if __name__ == "__main__":
    main()

In the main function, we first get the values of n and r from the user. Then we call the compute_permutations function and print the result.