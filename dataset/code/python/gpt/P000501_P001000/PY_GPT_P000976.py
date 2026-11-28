# problem title : Area of a Triangle Using Coordinates
# Solve the stated task using standard input and standard output.
def triangle_area(x1: float, y1: float, x2: float, y2: float, x3: float, y3: float) -> float:
    return 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))

if __name__ == '__main__':
    x1, y1, x2, y2, x3, y3 = map(float, input().split())
    print(f"{triangle_area(x1, y1, x2, y2, x3, y3):.6f}")
