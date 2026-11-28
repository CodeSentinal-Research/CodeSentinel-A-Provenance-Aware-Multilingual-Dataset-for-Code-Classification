Here is the Python code for the problem:

def average():
    a = float(input("Enter the first number: "))
    b = float(input("Enter the second number: "))
    c = float(input("Enter the third number: "))

    average = (a + b + c) / 3

    print("The average of the three numbers is: ", average)


if __name__ == "__main__":
    average()

In this program, we first ask for the three numbers from the user and calculate their average. We use the input function to get the user's input. The input function converts the user's input to a float. This is necessary because Python cannot directly compare the user's input with a float.

Then, we calculate the average by adding up the numbers and dividing by 3 (the total count of the numbers). Finally, we print the average.

The `if __name__ == "__main__":` part is to ensure that the main function is not executed when the script is imported as a module. This is a common way to avoid bugs in programs that import the module in other scripts.