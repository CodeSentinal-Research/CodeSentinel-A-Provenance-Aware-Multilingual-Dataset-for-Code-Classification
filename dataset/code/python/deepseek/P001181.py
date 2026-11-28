def can_reach_last():
    N = int(input().strip())
    max_jump = [int(i) for i in input().strip().split()]

    if N == 1:
        return "YES"

    reachable = [0] * N
    reachable[0] = 1

    for i in range(N):
        if reachable[i] == 1:
            for j in range(max_jump[i]):
                if reachable[i + j] == 0:
                    reachable[i + j] = 1

    return "YES" if reachable[-1] == 1 else "NO"


def main():
    N = int(input().strip())
    max_jump = [int(i) for i in input().strip().split()]

    print(can_reach_last())


if __name__ == "__main__":
    main()