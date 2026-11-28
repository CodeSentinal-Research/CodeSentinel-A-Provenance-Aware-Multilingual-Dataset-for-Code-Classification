def clone_graph(adj_list):
    cloned_vertices = {}

    def dfs(vertex):
        if vertex not in cloned_vertices:
            cloned_vertices[vertex] = set()
            for neighbor in adj_list[vertex]:
                cloned_vertices[vertex].add(neighbor)
                dfs(neighbor)

    dfs(0)

    cloned_graph = {i: set() for i in range(len(adj_list))}
    for vertex, neighbors in cloned_vertices.items():
        for neighbor in neighbors:
            cloned_graph[vertex].add(neighbor)

    return cloned_graph


def main():
    N = int(input().strip())

    adj_list = [set() for _ in range(N)]
    for _ in range(N):
        line = input().strip().split()
        vertex = int(line[0])
        for neighbour in line[1:]:
            adj_list[vertex].add(int(neighbour))

    cloned_graph = clone_graph(adj_list)

    for vertex, neighbors in cloned_graph.items():
        print(f"{vertex} {', '.join(str(neighbor) for neighbor in neighbors)}")


if __name__ == "__main__":
    main()