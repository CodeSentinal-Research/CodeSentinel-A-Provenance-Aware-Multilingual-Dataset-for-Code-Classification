def count_nodes_with_k_descendants(k):
    n = int(input())
    descendants = {}
    for _ in range(n):
        node, descendants_count = input().split()
        descendants[node] = int(descendants_count)

    count = 0
    for node, descendants_count in descendants.items():
        if descendants_count == k:
            count += 1

    print(count)

def main():
    k = int(input())
    count_nodes_with_k_descendants(k)

if __name__ == "__main__":
    main()