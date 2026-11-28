Here is the Python code for the problem. 

def power(x, n):
    if n == 0:
        return 1
    else:
        return x * power(x, n-1)

x = int(input("Enter the base number: "))
n = int(input("Enter the exponent: "))
print("Result is: ", power(x, n))

This program asks the user for two integers and computes their power using recursion.