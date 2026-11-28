Here's the Python code:

def fahrenheit_to_celsius(f):
    c = (f - 32) * 5/9
    return c

def main():
    f = float(input("Enter a temperature in Fahrenheit: "))
    c = fahrenheit_to_celsius(f)
    print("The temperature in Celsius is:", c)

if __name__ == "__main__":
    main()

In this program, we first define a function `fahrenheit_to_celsius` that takes a temperature in Fahrenheit as input and returns the temperature in Celsius. Then, in the `main` function, we handle user input and call the `fahrenheit_to_celsius` function to get the result.

We use `float(input("Enter a temperature in Fahrenheit: "))` to get user input and `print("The temperature in Celsius is:", c)` to print the result.

We also use `if __name__ == "__main__"` to ensure that the code is only run when the script is run directly. This is a common Python practice.