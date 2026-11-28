def max_units():
    N, T = map(int, input().split())
    truck = []
    for _ in range(N):
        boxes = list(map(int, input().split()))
        truck.append(boxes)
    truck.sort(reverse=True)
    max_units = 0
    for i in range(N):
        max_units += truck[i][0] * truck[i][1]
        if max_units > T:
            return max_units
    return max_units

print(max_units())