Here's a Python code to solve the problem using the Floyd-Warshall algorithm for all-pairs shortest path. It is assumed that the graph is represented as an adjacency list.

def floyd_warshall(graph):
    dist = graph
    for k in range(len(graph)):
        for i in range(len(graph)):
            for j in range(len(graph)):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
    return dist

def find_center(graph):
    dist = floyd_warshall(graph)
    min_distance = float('inf')
    center_vertices = []
    for i in range(len(graph)):
        for j in range(i+1, len(graph)):
            if dist[i][j] < min_distance:
                min_distance = dist[i][j]
                center_vertices = [j]
            elif dist[i][j] == min_distance:
                center_vertices.append(j)
    return sorted(center_vertices)

def main():
    n = int(input())
    graph = [[float('inf')] * n for _ in range(n)]
    for _ in range(n-1):
        u, v = map(int, input().split())
        graph[u-1][v-1] = graph[v-1][u-1] = 1
    print(find_center(graph))

if __name__ == '__main__':
    main()

This code first builds a graph using the input data. Then it finds all pairs of vertices that minimize the maximum distance to each other. The center vertices are printed in ascending order.

Please note that this is a simple implementation and may not work for all cases. For instance, it assumes that the graph is undirected and that the vertices are labeled from 1 to N. If your graph is directed or if the vertices are labeled from 0 to N-1, you would need to adjust the input and the code accordingly.