import math

def calculate_volume_of_cylinder():
    r = float(input("Enter the radius of the cylinder: "))
    h = float(input("Enter the height of the cylinder: "))
    if 0 < r <= 50 and 0 < h <= 50:
        volume = math.pi * r**2 * h
        print("The volume of the cylinder is: ", volume)
    else:
        print("Invalid input. Please enter numbers between 0 and 50 for radius and height.")

calculate_volume_of_cylinder()