Here is the Python code for the problem. 

def verify_tree(nodes, children, parent):
    node, child1, child2 = parent[0], parent[1], parent[2]
    if nodes[node][0] != -1:
        return False
    sum_val = nodes[node][1] + children[child1][1] + children[child2][1]
    if nodes[node][0] == -1 and sum_val == nodes[node][1]:
        nodes[node][0] = sum_val
    elif nodes[node][0] != -1 and sum_val != nodes[node][1]:
        return False
    return True

def solve(N, nodes, children):
    parent = [0, 0, 0]
    for i in range(1, N + 1):
        parent[0] = i
        if not verify_tree(nodes, children, parent):
            return 'NO'
    return 'YES'

def main():
    N = int(input())
    nodes = [[-1, -1] for _ in range(N + 1)]
    children = [[0, 0] for _ in range(N + 1)]
    for i in range(1, N + 1):
        parent = list(map(int, input().split()))
        children[parent[0]] = [parent[1], parent[2]]
        if nodes[parent[1]][0] != -1 or nodes[parent[2]][0] != -1:
            children[parent[0]][0] = nodes[parent[1]][0] + nodes[parent[2]][0]
    print(solve(N, nodes, children))

if __name__ == "__main__":
    main()

In this code, `verify_tree` function checks whether the node and its children have the sum equal to the node's value. If not, it marks the node as -1 and returns False. `solve` function uses `verify_tree` to verify the tree. If any node fails to satisfy the children sum property, it returns 'NO', otherwise 'YES'. The input is read by the `main` function.