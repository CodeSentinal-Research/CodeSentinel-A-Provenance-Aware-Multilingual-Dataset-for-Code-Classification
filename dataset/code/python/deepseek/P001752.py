def count_ancestors():
    n = int(input())
    parents = []
    for _ in range(n):
        parents.append(list(map(int, input().split())))

    ancestors = [0 for _ in range(n)]
    for parent in parents:
        for child in parent[1:]:
            ancestors[child] = ancestors[parent[0]] + 1

    for count in ancestors:
        print(count)

if __name__ == "__main__":
    count_ancestors()