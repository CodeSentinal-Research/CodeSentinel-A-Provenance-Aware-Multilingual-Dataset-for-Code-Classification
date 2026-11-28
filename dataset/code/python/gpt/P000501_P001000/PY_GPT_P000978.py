# problem title : Determine Triangle Type from Coordinates
# Solve the stated task using standard input and standard output.
def triangle_type(x1: int, y1: int, x2: int, y2: int, x3: int, y3: int) -> str:
    # Check collinear
    if (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) == 0:
        return "Not a Triangle"

    d1 = (x1 - x2)**2 + (y1 - y2)**2
    d2 = (x2 - x3)**2 + (y2 - y3)**2
    d3 = (x3 - x1)**2 + (y3 - y1)**2

    if d1 == d2 == d3:
        return "Equilateral"
    elif d1 == d2 or d2 == d3 or d3 == d1:
        return "Isosceles"
    else:
        return "Scalene"

if __name__ == '__main__':
    x1, y1, x2, y2, x3, y3 = map(int, input().split())
    print(triangle_type(x1, y1, x2, y2, x3, y3))
