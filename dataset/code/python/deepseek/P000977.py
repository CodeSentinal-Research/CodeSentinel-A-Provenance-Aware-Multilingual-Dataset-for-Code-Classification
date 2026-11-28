def are_collinear(point1, point2, point3):
    if not ((-10**9 <= point1 <= point2 <= point3 <= 10**9) and (type(point1) == type(point2) == type(point3) == tuple)):
        raise ValueError("All coordinates must be within the range -10^9 <= coordinates <= 10^9 and they must be of tuple type.")

    if (point1[0]*(point2[1]-point3[1]) + point2[0]*(point3[1]-point1[1]) + point3[0]*(point1[1]-point2[1])) == 0:
        return True
    else:
        return False

def main():
    point1 = tuple(int(x) for x in input().split())
    point2 = tuple(int(x) for x in input().split())
    point3 = tuple(int(x) for x in input().split())

    print(are_collinear(point1, point2, point3))

if __name__ == "__main__":
    main()