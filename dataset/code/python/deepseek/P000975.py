Here is the Python code for your problem:

def midpoint(x1, y1, x2, y2):
    mid_x = (x1 + x2) / 2
    mid_y = (y1 + y2) / 2
    return mid_x, mid_y

while True:
    try:
        x1 = int(input('Enter x1: '))
        x2 = int(input('Enter x2: '))
        y1 = int(input('Enter y1: '))
        y2 = int(input('Enter y2: '))

        if (x1, y1, x2, y2) != (x, y, x, y):
            print('Invalid input. Please enter the endpoints of a line segment.')
            continue

        mid_x, mid_y = midpoint(x1, y1, x2, y2)
        print('Midpoint coordinates:', mid_x, mid_y)
        break
    except ValueError:
        print('Invalid input. Please enter integers.')

In this code, the midpoint of a line segment is calculated by taking the average of the x-coordinates and y-coordinates of the two endpoints. The function `midpoint` takes in four integers as input (x1, y1, x2, y2) and returns the midpoint coordinates. The main part of the code handles input, ensuring that the input is a valid line segment (i.e., integers). If the input is not valid, the code will continue to prompt the user for input until a valid line segment is provided.