Here is the Python code for converting Celsius to Fahrenheit:

def celsius_to_fahrenheit(c):
    return c * 9.0 / 5.0 + 32

c = float(input("Enter temperature in Celsius: "))
print("Temperature in Fahrenheit: ", celsius_to_fahrenheit(c))

This program will ask the user to input a temperature in Celsius, then it will convert the temperature to Fahrenheit using the formula `f = c * 9.0 / 5.0 + 32` and print the result.