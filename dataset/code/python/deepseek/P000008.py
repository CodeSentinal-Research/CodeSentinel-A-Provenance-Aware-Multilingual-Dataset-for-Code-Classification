Here is the Python code:

def check_number(n):
    if n > 0:
        print('Positive')
    elif n < 0:
        print('Negative')
    else:
        print('Zero')

n = int(input("Enter an integer: "))
check_number(n)

In this code, the function check_number(n) takes an integer as an input and checks if it is positive, negative or zero. The output is printed on the console. The main function calls the function and asks for the input and prints the output.