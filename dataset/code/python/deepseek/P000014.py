Here is the Python code that calculates the area of a rectangle given length and breadth:

def calculate_area():
    length = int(input("Enter the length of the rectangle: "))
    breadth = int(input("Enter the breadth of the rectangle: "))

    if 1 <= length <= 1000 and 1 <= breadth <= 1000:
        area = length * breadth
        print("The area of the rectangle is: ", area)
    else:
        print("Invalid input. Please enter numbers between 1 and 1000.")

calculate_area()
In this code, the function `calculate_area` is defined. It asks for length and breadth input from the user. If the input is valid (i.e., between 1 and 1000), it calculates the area of the rectangle and prints it. If the input is not valid, it prints an error message.