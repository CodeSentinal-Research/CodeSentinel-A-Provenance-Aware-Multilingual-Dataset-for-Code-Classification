Here is the Python code with the main function and input handling:

def find_quotient_and_remainder(a, b):
    if b == 0:
        return "Division by zero error"
    quotient = a // b
    remainder = a % b
    return quotient, remainder

if __name__ == "__main__":
    a = int(input("Enter the first number: "))
    b = int(input("Enter the second number: "))
    if a >= 0 and a <= 10000 and b >= 1 and b <= 10000:
        quotient, remainder = find_quotient_and_remainder(a, b)
        print(f"Quotient: {quotient}, Remainder: {remainder}")
    else:
        print("Input out of bounds. Please enter numbers between 0 and 10000.")

In this code, the `find_quotient_and_remainder` function calculates the quotient and remainder of a division operation. If `b` is zero, it returns an error message. The input numbers are taken from the user in the `main` function.