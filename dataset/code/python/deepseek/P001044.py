Here is the Python code:

def get_level(arr, i):
    level = 0
    while i > 0:
        level += 1
        i = i // 2
    return level

def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    i = int(input().strip())
    print(get_level(arr, i))

if __name__ == "__main__":
    main()

The `get_level` function calculates the level of a node in a binary heap by iteratively dividing the index by 2 until it becomes 0 (when the node is at the root of the heap). The level of the node is the number of divisions it took to reach the root.

The `main` function reads the number of nodes (N), a list of the nodes, and the index of the node to find the level of, and then prints the level of the node.