def is_duplicate(node_values):
    node_set = set()
    for value in node_values:
        if value in node_set:
            return "YES"
        node_set.add(value)
    return "NO"

def main():
    N = int(input().strip())
    node_values = list(map(int, [input().strip() for _ in range(N)]))
    print(is_duplicate(node_values))

if __name__ == "__main__":
    main()