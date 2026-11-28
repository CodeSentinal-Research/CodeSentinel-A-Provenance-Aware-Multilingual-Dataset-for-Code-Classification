import math

def calculate_area(radius):
    pi = math.pi
    area = pi * (radius ** 2)
    return area

def main():
    radius = float(input("Enter the radius of the circle: "))
    while radius <= 0 or radius > 100:
        print("Invalid input. Please enter a number between 0 and 100.")
        radius = float(input("Enter the radius of the circle: "))
    area = calculate_area(radius)
    print("The area of the circle is: ", area)

if __name__ == "__main__":
    main()