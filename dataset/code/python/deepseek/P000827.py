def findRadius(houses, heaters):
    heaters.sort()
    radius = 0

    for house in houses:
        found_heater = False
        min_distance = float('inf')

        for heater in heaters:
            distance = abs(house - heater)
            if distance < min_distance:
                min_distance = distance
                found_heater = True

        if found_heater:
            radius = max(radius, min_distance)

    return radius


def main():
    n = int(input("Enter the number of houses: "))
    houses = list(map(int, input("Enter the positions of houses: ").split()))
    m = int(input("Enter the number of heaters: "))
    heaters = list(map(int, input("Enter the positions of heaters: ").split()))

    print(findRadius(houses, heaters))


if __name__ == "__main__":
    main()