def solve(N, nodes, K):
    nodes_set = set(nodes)

    for node in nodes:
        complement = K - node

        if complement in nodes_set:
            return 'YES'

    return 'NO'


def main():
    N = int(input().strip())
    nodes = list(map(int, (input() for _ in range(N))))
    K = int(input().strip())

    print(solve(N, nodes, K))


if __name__ == "__main__":
    main()