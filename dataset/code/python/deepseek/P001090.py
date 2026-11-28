def find_diameter(n, edges):
    graph = [[] for _ in range(n+1)]
    for edge in edges:
        u, v = edge
        graph[u].append(v)
        graph[v].append(u)

    depths = [0] * (n+1)
    parent = [0] * (n+1)
    max_depth = 0
    max_depth_vertices = []

    def dfs(node, parent_node):
        nonlocal max_depth, max_depth_vertices
        depths[node] = depths[parent_node] + 1
        if depths[node] > max_depth:
            max_depth = depths[node]
            max_depth_vertices = [node]
        elif depths[node] == max_depth:
            max_depth_vertices.append(node)
        for child in graph[node]:
            if child == parent_node:
                continue
            dfs(child, node)

    dfs(1, 0)

    max_depth_vertices = [max_depth_vertices[0]]
    max_depth_vertices.extend(max_depth_vertices[1:])

    diameter = max_depth_vertices[-1]
    for vertex in max_depth_vertices[:-1]:
        if not graph[vertex]:
            diameter = vertex
            break
    return diameter


def main():
    n = int(input())
    edges = [(int(input()), int(input())) for _ in range(n-1)]
    print(find_diameter(n, edges))


if __name__ == '__main__':
    main()
This python code defines a function `find_diameter` that uses depth-first search to find the longest path in the tree. It first creates a list `graph` representing the tree, and then uses a list `depths` to store the depth of each node. The function `dfs` is a helper function that performs the depth-first search and updates the maximum depth and vertices. Finally, it finds the longest path by iterating through the vertices in reverse order of their depth and returns the first vertex that is not connected to any other vertices.