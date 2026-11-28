Here is the Python code for the problem:

def add(a: int, b: int) -> int:
    while b:
        carry = a & b
        a = a ^ b
        b = carry << 1
    return a

if __name__ == "__main__":
    a = int(input("Enter first integer: "))
    b = int(input("Enter second integer: "))
    print("Sum is: ", add(a, b))

In this code, the function `add` computes the sum of two integers `a` and `b` using bitwise operations. The while loop continues until `b` becomes 0. In each iteration, the carry is calculated as `a & b` and `a ^ b` are performed. The carry is shifted left by 1 to move it to the left.

In the main function, user is asked to enter two integers and the result is printed.