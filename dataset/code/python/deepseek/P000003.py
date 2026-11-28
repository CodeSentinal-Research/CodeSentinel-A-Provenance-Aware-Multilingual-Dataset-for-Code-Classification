Here's the Python code for the given problem:

def multiply(a, b):
    return a * b

def main():
    a = int(input("Enter the first number: "))
    b = int(input("Enter the second number: "))
    print("The product of the two numbers is: ", multiply(a, b))

if __name__ == "__main__":
    main()

In this code, we first define a function `multiply` that takes two integers as input and returns their product. Then we define a `main` function which handles user input, calls `multiply` function to compute the product, and prints the result. The `main` function is the entry point of our program. 

Please note that the `input` function in Python reads input from the user as a string. So, if you enter a number (like 5 or 100), the function will interpret it as a string and not as an integer. Hence, we need to convert the string to an integer when passing it to the `multiply` function.

For instance, if you run this program and enter `5` and `100` when prompted, the program will print `500` as the result.