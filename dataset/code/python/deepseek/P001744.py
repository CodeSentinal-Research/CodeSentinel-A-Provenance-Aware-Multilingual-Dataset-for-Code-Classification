Here is the Python code:

def check_internal_nodes():
    N = int(input())
    node_ids = set()
    for _ in range(N):
        line = input().split()
        if len(line) > 1:
            node_id = int(line[0])
            node_ids.add(node_id)
        elif len(line) == 1:
            node_ids_edge = set(int(node) for node in line[1:])
            if not node_ids_edge.issubset(node_ids):
                return "NO"
    if not node_ids.issubset(node_ids_edge):
        return "NO"
    for node_id in node_ids:
        node_ids_parent = set(node_id for node_id in line[1:] if int(node_id) in node_ids)
        if len(node_ids_parent) != 1:
            return "NO"
    return "YES"

print(check_internal_nodes())

This code reads the input N times, and for each input line, it processes it. If it processes a node with more than one child, it returns "NO". If it processes a node with one child, it adds the child to a set of node ids. If it does not process all nodes and the set of node ids contains more than one node, it returns "NO". If it does not process all nodes and the set of node ids does not contain all nodes, it returns "NO". If all nodes have exactly one child, it returns "YES".