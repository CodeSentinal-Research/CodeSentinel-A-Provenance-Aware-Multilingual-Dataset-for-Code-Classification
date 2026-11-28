import math

def calculate_circumference(radius):
    return 2 * math.pi * radius

def main():
    radius = float(input("Enter the radius of the circle: "))
    while not (0 <= radius <= 100):
        print("Invalid input, please enter a value between 0 and 100 for radius.")
        radius = float(input("Enter the radius of the circle: "))
    print("The circumference of the circle is: ", calculate_circumference(radius))

if __name__ == "__main__":
    main()