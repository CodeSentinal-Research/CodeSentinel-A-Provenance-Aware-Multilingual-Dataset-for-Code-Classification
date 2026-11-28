import math

def euclidean_distance(x1: float, y1: float, x2: float, y2: float) -> float:
    return math.hypot(x2 - x1, y2 - y1)

if __name__ == '__main__':
    x1, y1, x2, y2 = map(float, input().split())
    print(f"{euclidean_distance(x1, y1, x2, y2):.6f}")