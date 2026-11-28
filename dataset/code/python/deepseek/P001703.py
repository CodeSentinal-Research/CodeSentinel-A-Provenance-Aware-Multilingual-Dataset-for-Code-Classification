def read_tree():
    n = int(input().strip())
    nodes = [int(input().strip()) for _ in range(n)]
    nodes.sort()
    left = [int(input().strip()) for _ in range(n)]
    right = [int(input().strip()) for _ in range(n)]
    return nodes, left, right

def find_max_difference(nodes, left, right):
    max_diff = max(abs(nodes[0] - left[0]), abs(nodes[-1] - right[0]))
    for i in range(1, len(nodes)):
        max_diff = max(max_diff, abs(nodes[i] - left[i]), abs(nodes[i] - right[i]))
    return max_diff

def main():
    nodes, left, right = read_tree()
    max_difference = find_max_difference(nodes, left, right)
    print(max_difference)

if __name__ == "__main__":
    main()