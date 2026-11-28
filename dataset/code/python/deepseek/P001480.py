def partition_labels(S):
    last = {c: i for i, c in enumerate(S)}
    anchor = last[S[0]]
    partition = [anchor]

    for i, c in enumerate(S):
        if last[c] > anchor:
            anchor = last[c]
        if last[c] > i:
            partition.append(last[c])

    return partition


def main():
    S = input()
    partition_sizes = partition_labels(S)
    print(partition_sizes)


if __name__ == "__main__":
    main()