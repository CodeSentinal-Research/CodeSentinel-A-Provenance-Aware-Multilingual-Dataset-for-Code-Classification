import sys
def solve():
    d = sys.stdin.read().split()
    x1, y1 = int(d[0]), int(d[1])
    x2, y2 = int(d[2]), int(d[3])
    x3, y3 = int(d[4]), int(d[5])
    cross = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1)
    if cross == 0:
        print("Not a Triangle")
        return
    d1 = (x2 - x1)**2 + (y2 - y1)**2
    d2 = (x3 - x2)**2 + (y3 - y2)**2
    d3 = (x1 - x3)**2 + (y1 - y3)**2
    if d1 == d2 == d3:
        print("Equilateral")
    elif d1 == d2 or d2 == d3 or d1 == d3:
        print("Isosceles")
    else:
        print("Scalene")
solve()
