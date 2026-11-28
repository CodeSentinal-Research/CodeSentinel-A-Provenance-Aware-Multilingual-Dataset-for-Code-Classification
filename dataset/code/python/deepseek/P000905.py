Sure, here is the Python code for the problem:

def modular_subtraction(A, B, M):
    return (A - B) % M

A = int(input("Enter the first integer: "))
B = int(input("Enter the second integer: "))
M = int(input("Enter the modulus: "))

result = modular_subtraction(A, B, M)
print("The result of modular subtraction is:", result)

This program first defines a function `modular_subtraction` which performs modular subtraction on two integers and a modulus. Then it takes three inputs: two integers `A` and `B`, and an integer `M`. It then calls the function with these inputs and prints the result.

Please note that Python's `input()` function reads a line of input from the user. If you want to handle the input in a more sophisticated way, you'll need to modify this code accordingly. Also, the provided constraint for the modulus (`M`) should be a large enough number that it can fit into a Python `int` or `long`.