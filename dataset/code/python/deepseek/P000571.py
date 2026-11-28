def hot_potato(N, K):
    players = list(range(1, N+1))
    eliminated = []
    current = 0

    while len(players) > 1:
        for _ in range(K):
            current = (current + 1) % len(players)
            eliminated.append(players.pop(current))

        print(f'Eliminated {eliminated[-1]}')
        eliminated = []

    return players[0]


def main():
    N, K = map(int, input().split())
    print(hot_potato(N, K))


if __name__ == '__main__':
    main()