def subtract_two_numbers(a, b):
    return a - b

try:
    a = int(input("Enter the first number: "))
    b = int(input("Enter the second number: "))
    print("Result:", subtract_two_numbers(a, b))
except ValueError:
    print("Invalid input. Please enter integers only.")