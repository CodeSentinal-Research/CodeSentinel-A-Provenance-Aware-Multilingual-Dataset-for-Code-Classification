Here is the Python code:

def triangle_type(x1, y1, x2, y2, x3, y3):
    if ((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)) != 0):
        return "Not a Triangle"

    elif ((x1*(y1-y2) + x2*(y2-y3) + x3*(y3-y1)) == 0):
        return "Equilateral Isosceles Scalene"

    else:
        return "Scalene"

def main():
    points = input("Enter the coordinates of the three points separated by space: ")
    points = [list(map(int, point.split())) for point in points.split(",")]
    print(triangle_type(points[0][0], points[0][1], points[1][0], points[1][1], points[2][0], points[2][1]))

if __name__ == "__main__":
    main()

This program will take the coordinates of the three points as input, then call the `triangle_type` function with these coordinates. The `triangle_type` function will return the type of the triangle based on the coordinates. The input handling in the `main` function is simple, the user can input the coordinates of the points separated by a comma.