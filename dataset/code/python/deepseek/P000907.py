Here is a Python code using the fast modular exponentiation algorithm:

def fast_modular_exp(A, B, M):
    if B == 1:
        return A % M
    else:
        temp = fast_modular_exp(A, B // 2, M)
        temp *= temp
        if B % 2 != 0:
            temp *= A
        return temp % M

def main():
    A = int(input("Enter A: "))
    B = int(input("Enter B: "))
    M = int(input("Enter M: "))
    print(fast_modular_exp(A, B, M))

if __name__ == "__main__":
    main()

This code first declares a function `fast_modular_exp` which uses a divide-and-conquer strategy to compute the modular exponentiation. It recursively calls itself until the base case is reached, then combines the results back up.

The `main` function handles input and outputs, and is the entry point of the program.

Please note that this code will not work correctly for large inputs due to Python's recursion limit. It's recommended to use a language that allows for tail recursion optimization, or use a language that supports arbitrary precision arithmetic, such as Python 3.4 or later.