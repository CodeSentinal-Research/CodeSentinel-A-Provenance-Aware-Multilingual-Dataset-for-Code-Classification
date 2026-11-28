Here is the Python code to solve the problem:

def multiply(num1, num2):
    num1 = int(num1)
    num2 = int(num2)
    product = num1 * num2
    product = str(product)
    return product

This code defines a function `multiply` that takes in two strings, converts them to integers, multiplies them, and then converts the product back to a string. The main function is as follows:

def main():
    num1 = input("Enter the first number: ")
    num2 = input("Enter the second number: ")
    product = multiply(num1, num2)
    print("The product is: " + product)

if __name__ == "__main__":
    main()

This code asks the user to enter two numbers, calls the `multiply` function with these numbers, and prints the product. Note that this code assumes that the user will always provide valid input. If the user may provide invalid input (e.g., a string that can't be converted to an integer), you might want to add error handling code to handle these situations.