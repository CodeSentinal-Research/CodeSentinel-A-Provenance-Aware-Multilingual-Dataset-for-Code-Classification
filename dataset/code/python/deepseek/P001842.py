Here is the Python code for finding the union of two binary search trees.

def union(tree1, tree2):
    tree1 = set(tree1)
    tree2 = set(tree2)

    return tree1.union(tree2)

def main():
    N1 = int(input())
    tree1 = set(int(input()) for _ in range(N1))

    N2 = int(input())
    tree2 = set(int(input()) for _ in range(N2))

    print(union(tree1, tree2))

if __name__ == "__main__":
    main()

This code will work for your given problem statement. It first reads the number of nodes in the first tree and the nodes themselves. Then it reads the number of nodes in the second tree and the nodes themselves. It then calls the `union` function with these trees as arguments and prints the result.