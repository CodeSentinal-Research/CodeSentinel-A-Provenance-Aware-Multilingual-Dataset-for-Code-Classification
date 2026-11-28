Here is the Python code to solve the problem. The code first reads the number of nodes and then the tree. For each node, it calculates the size of the subtree rooted at that node, counts the number of nodes in the left and right subtrees, and finally, if the number of nodes in the left or right subtrees is greater than the other, it is the centroid of the tree.

def main():
    N = int(input().strip())
    nodes = []

    for i in range(N):
        node = list(map(int, input().strip().split()))
        nodes.append(node)

    centroid = find_centroid(nodes, 0, N)
    print(centroid)

def find_centroid(nodes, node, start, end):
    if start == end:
        return nodes[start][0]

    left = sum(nodes[i][1] for i in range(start, end) if nodes[i][0] < nodes[node][0])
    right = sum(nodes[i][1] for i in range(start, end) if nodes[i][0] > nodes[node][0])

    if left > right:
        return find_centroid(nodes, node, start, start + right)
    else:
        return find_centroid(nodes, node, start + right, end)

if __name__ == "__main__":
    main()
In this code, `nodes` is a list of lists, where each inner list represents a node and contains the value and the number of its children. The `find_centroid` function calculates the centroid of a subtree rooted at `node`. It recursively searches for the centroid by comparing the sizes of the left and right subtrees.