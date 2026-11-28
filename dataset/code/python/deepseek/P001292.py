def max_eliminated_monsters():
    N = int(input().strip())
    distances = list(map(int, input().strip().split()))
    speeds = list(map(int, input().strip().split()))

    max_distance = max(distances)
    max_speed = max(speeds)

    max_eliminated = max_distance // max_speed

    print(max_eliminated)

max_eliminated_monsters()