def midpoint(x1: float, y1: float, x2: float, y2: float):
    return (x1 + x2) / 2.0, (y1 + y2) / 2.0

if __name__ == '__main__':
    x1, y1, x2, y2 = map(float, input().split())
    mx, my = midpoint(x1, y1, x2, y2)
    print(f"{mx:.6f} {my:.6f}")