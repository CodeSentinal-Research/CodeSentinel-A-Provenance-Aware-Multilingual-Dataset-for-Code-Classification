Sure, here is the Python code for your problem:

def check_internal_nodes(tree):
    for node in tree:
        if node[1] in tree[node[0]]:
            if len(tree[node[0]][node[1]]) == 1:
                return "NO"
    return "YES"

if __name__ == "__main__":
    N = int(input().strip())
    tree = {}
    for _ in range(N):
        node = list(map(int, input().strip().split()))
        if node[0] not in tree:
            tree[node[0]] = {node[1]: [], node[2]: []}
        else:
            tree[node[0]][node[1]] = [node[2]]
            tree[node[0]][node[2]] = [node[1]]
    print(check_internal_nodes(tree))
This code first reads the number of nodes N and then the edges between the nodes. It then constructs a dictionary where the keys are the nodes and the values are dictionaries representing the children of each node. Finally, it calls the `check_internal_nodes` function which checks whether every internal node has exactly two children or not.

Note: This code assumes that the nodes are numbered starting from 1. If your nodes are numbered from 0, you should adjust the code accordingly.