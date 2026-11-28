Here is the Python code:

def num_boomerangs(N):
    points = []
    for i in range(N):
        x, y = map(int, input().split())
        points.append((x, y))

    boomerangs = 0
    for p1 in points:
        distance_dict = {}
        for p2 in points:
            if p1 != p2:
                distance = ((p2[0] - p1[0]) ** 2 + (p2[1] - p1[1]) ** 2) ** 0.5
                distance_dict[distance] = distance_dict.get(distance, 0) + 1

        for count in distance_dict.values():
            boomerangs += count * (count - 1)

    print(boomerangs // 2)


if __name__ == "__main__":
    N = int(input())
    num_boomerangs(N)

In this code, the main function num_boomerangs takes an integer N as input, which is the number of points. It then reads N lines of input, each containing two integers representing the coordinates of a point. The coordinates are stored in a list of tuples.

The function then iterates over each point in the list. For each point, it calculates the distances from all other points. It counts the occurrences of each distance and multiplies the counts by the number of boomerangs if the distance is greater than 0, since a boomerang is formed by two points that are at a distance of 0.

The final count of boomerangs is divided by 2 (since each boomerang is counted twice), and the result is printed to the console.