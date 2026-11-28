Here is the Python code for finding Eulerian path in an undirected graph:

from collections import defaultdict

def add_edge(graph, node1, node2):
    graph[node1].append(node2)
    graph[node2].append(node1)

def find_eulerian_path(graph):
    odd_edges = sum(len(node_edges) % 2 for node_edges in graph.values())
    if odd_edges > 2:
        return "IMPOSSIBLE"
    elif odd_edges == 2:
        for node, edges in graph.items():
            if len(edges) % 2:
                start = node
                graph[start] = [graph[start][0]]
                add_edge(graph, graph[start][0], node)
                return [node, start] + find_eulerian_path(graph)
    else:
        start = next(node for node, edges in graph.items() if len(edges) % 2)
        return [start, next(node for node, edges in graph.items() if len(edges) % 2)] + \
               find_eulerian_path({node: edges for node, edges in graph.items() if node != start})

def main():
    n, m = map(int, input().split())
    graph = defaultdict(list)
    for _ in range(m):
        u, v = map(int, input().split())
        add_edge(graph, u, v)
    path = find_eulerian_path(graph)
    print('\n'.join(map(str, path)))

if __name__ == '__main__':
    main()

This code first reads the number of nodes and edges from the input, then it creates a graph from the edges. It then calls the `find_eulerian_path` function, which recursively tries to find an Eulerian path. If it cannot find a path, it returns "IMPOSSIBLE". If it can, it prints the path.

Note: The code assumes that the graph is a connected graph and each node has at least one edge. If the graph is not connected, then the Eulerian path cannot exist, so you would need to add additional code to handle this case.