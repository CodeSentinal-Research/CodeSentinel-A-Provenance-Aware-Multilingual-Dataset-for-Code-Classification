Here's a Python solution for the Car Fleet II problem:

def getCollisionTimes(cars):
    stack = []
    res = [0] * len(cars)

    for i in range(len(cars) - 1, -1, -1):
        car = cars[i]

        while stack:
            nextCar, time, speedDiff, posDiff |
            if car[1] <= speedDiff / car[3] and car[2] < posDiff / speedDiff:
                res[i] = time + (posDiff - car[2]) / speedDiff
                break
            elif car[1] > speedDiff / car[3] and car[2] < posDiff / speedDiff:
                break

            nextCarPos, nextCarSpeed = stack.pop()
            speedDiff = car[1] - nextCarSpeed
            posDiff = car[2] - nextCarPos
            time += -1 / car[3] if speedDiff != 0 else 0

        if not stack:
            res[i] = -1
        else:
            stack.append((car[2], time, speedDiff, posDiff))

    return res


def main():
    cars = [(1, 2, 10), (1, 1, 10), (10, 1, 10)]
    print(getCollisionTimes(cars))


if __name__ == '__main__':
    main()

In this code, we maintain a stack of cars that we haven't yet considered. For each car, we try to determine the time when the car collides with the next car in the stack. If the car is moving faster than the next car, it collides with the next car immediately. If it's moving slower than the next car, it's kept moving ahead. If there's no car ahead in the stack or the stack top car is slower than the current car, we append the current car to the stack.