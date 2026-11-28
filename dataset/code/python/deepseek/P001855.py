Here's the Python code for the problem:

def min_inserts(n, bst):
    keys = []
    for line in bst:
        keys += line.split()[1:]
    keys = sorted(list(set(keys)))

    dp = [0] * (len(keys) + 1)
    for i in range(len(keys) - 1, -1, -1):
        dp[i + 1] = max(dp[i + 1], dp[i] + keys[i].bit_length() + 1)
        if i + 1 < len(keys) and dp[i + 2] < dp[i] + keys[i + 1].bit_length() + 1:
            dp[i + 1] = dp[i + 2]

    return len(bst) - dp[len(keys)]


def main():
    n = int(input().strip())
    bst = [input().strip() for _ in range(n)]
    print(min_inserts(n, bst))


if __name__ == "__main__":
    main()

This code first reads the number of keys and the keys themselves from the input. Then it sorts the keys and calculates the longest bit length possible for each key. Finally, it calculates the minimum number of insertions required to make the resulting tree a complete Binary Search Tree.