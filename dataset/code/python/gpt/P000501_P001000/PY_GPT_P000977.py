# problem title : Check Collinearity of Three Points
# Solve the stated task using standard input and standard output.
def are_collinear(x1: int, y1: int, x2: int, y2: int, x3: int, y3: int) -> bool:
    return (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) == 0

if __name__ == '__main__':
    x1, y1, x2, y2, x3, y3 = map(int, input().split())
    print("YES" if are_collinear(x1, y1, x2, y2, x3, y3) else "NO")
