Here is the Python code for the problem:

from collections import defaultdict

def dfs(graph, start, end, path=[]):
    path = path + [start]
    if start == end:
        print(path)
    else:
        for node in graph[start]:
            dfs(graph, node, end, path)

def solve(V, graph, start, end):
    dfs(graph, start, end)

def main():
    V, E = map(int, input().split())
    graph = defaultdict(list)

    for _ in range(E):
        u, v = map(int, input().split())
        graph[u].append(v)

    start, end = map(int, input().split())
    solve(V, graph, start, end)

if __name__ == "__main__":
    main()

This code first reads the number of vertices (V) and edges (E) from the input, and then reads the edges into the graph. Then it reads the start and end nodes from the input. The solve function uses the dfs function to print all possible paths from the start node to the end node. The main function is the entry point of the program and reads the input and calls the solve function.