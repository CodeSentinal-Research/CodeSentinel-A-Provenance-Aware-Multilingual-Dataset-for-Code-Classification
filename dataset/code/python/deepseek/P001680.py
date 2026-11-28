Here is a Python solution using the Breadth-First Search (BFS) algorithm to solve the problem:

from collections import deque

def largest_value_in_every_row():
    n = int(input().strip())

    nodes = list(map(int, input().strip().split()))
    nodes.append(None)  
    tree = [[] for _ in range(n)]
    for i in range(n):
        child_index = 2 * i + 1
        if child_index < n:  
            tree[i].append(nodes[child_index])
            tree[child_index] = [nodes[child_index]]
        if child_index + 1 < n:  
            tree[i].append(nodes[child