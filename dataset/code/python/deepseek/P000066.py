Sure, here is the Python code for calculating the area of a triangle.

def calculate_area():
    base = float(input("Enter the base of the triangle: "))
    height = float(input("Enter the height of the triangle: "))
    area = 0.5 * base * height
    print("The area of the triangle is: ", area)

if __name__ == "__main__":
    calculate_area()

In this code, we first read the base and height of the triangle from the user. The area of a triangle is calculated as 0.5 * base * height, and then we print the area.

Please note, in the code above, we are using `input` function to take user input, which is a bit dangerous if we are not careful. In a real-world scenario, you would probably want to validate the input to make sure it's a number and within the appropriate range.