Here is the Python code for the problem:

def solve(n, binary_tree):
    total_sum = 0

    for i in range(n):
        binary_number = binary_tree[i]
        current_node = int(binary_number, 2)
        total_sum += current_node

    return total_sum

def main():
    n = int(input().strip())
    binary_tree = [input().strip() for _ in range(n)]
    print(solve(n, binary_tree))

if __name__ == "__main__":
    main()

This code first reads the number of nodes, and then reads the binary tree. It then calls the `solve` function with the number of nodes and the binary tree, and prints the result.