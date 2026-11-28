def max_thieves_caught(N, K, street):
    police_cars = [0] * N
    max_thieves = 0
    thieves = 0

    for i in range(N):
        if street[i] == 'T':
            thieves += 1
        elif street[i] == 'P' and thieves > 0:
            police_cars[i - thieves] = 1
            thieves -= 1

    for i in range(N - 1, -1, -1):
        if street[i] == 'T' and police_cars[i] == 0:
            max_thieves += 1

    return max_thieves


def main():
    N, K = map(int, input().split())
    street = input()

    print(max_thieves_caught(N, K, street))


if __name__ == '__main__':
    main()