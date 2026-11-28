# problem title : Count Leaf Nodes in a Heap
# Solve the stated task using standard input and standard output.
def count_leaf_nodes(n: int) -> int:
    return (n + 1) // 2

if __name__ == '__main__':
    n = int(input())
    print(count_leaf_nodes(n))
