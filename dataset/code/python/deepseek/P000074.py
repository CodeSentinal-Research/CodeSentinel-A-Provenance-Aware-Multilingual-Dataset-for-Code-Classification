import math

def calculate_sphere_volume(radius):
    if 0 < radius <= 50:
        volume = (4/3) * math.pi * radius**3
        return volume
    else:
        return "Invalid radius. Please enter a number between 0 and 50."

try:
    radius = float(input("Enter the radius of the sphere: "))
    print("The volume of the sphere is: ", calculate_sphere_volume(radius))
except ValueError:
    print("Invalid input. Please enter a number.")