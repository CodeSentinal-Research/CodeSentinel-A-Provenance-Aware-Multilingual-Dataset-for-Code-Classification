def main():
    N = int(input())
    rabbits = list(map(int, input().split()))

    rabbits.sort()

    min_rabbits = 0
    for i in range(N):
        if i % 2 == 0:
            min_rabbits += rabbits[i]

    print(min_rabbits)


if __name__ == "__main__":
    main()