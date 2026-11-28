Here is the python code:

import sys
import math
import heapq

def read_input():
    N, K = map(int, sys.stdin.readline().split())
    points = [tuple(map(int, sys.stdin.readline().split())) for _ in range(N)]
    return N, K, points

def euclidean_distance(point1, point2):
    return math.sqrt((point1[0] - point2[0]) ** 2 + (point1[1] - point2[1]) ** 2)

def closest_points(N, K, points):
    points.sort(key=lambda point: euclidean_distance(point, (0, 0)))
    heapq.heapify(points)
    result = [heapq.heappop(points) for _ in range(K)]
    return result

def main():
    N, K, points = read_input()
    result = closest_points(N, K, points)
    for point in result:
        print(point)

if __name__ == "__main__":
    main()

In this code, we use a list comprehension to create a list of tuples, where each tuple is a point from the input. The `euclidean_distance` function calculates the Euclidean distance between two points. The `closest_points` function sorts the points by their distance from the origin, then uses a priority queue to find the K closest points. The `main` function reads the input and prints the K closest points.