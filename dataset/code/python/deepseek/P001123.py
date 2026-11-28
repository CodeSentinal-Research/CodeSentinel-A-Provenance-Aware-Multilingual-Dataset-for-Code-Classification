def main():
    N, M, T = map(int, input().split())
    graph = [[] for _ in range(N)]
    for _ in range(M):
        u, v, w = map(int, input().split())
        graph[u-1].append((v-1, w))
        graph[v-1].append((u-1, w))
    
    reachable_cities = {i: set() for i in range(N)}
    for i in range(N):
        stack = [(i, 0)]
        while stack:
            node, dist = stack.pop()
            if dist <= T and node not in reachable_cities[i]:
                reachable_cities[i].add(node)
                stack.extend((j, dist + w) for j, w in graph[node] if j not in reachable_cities[i])
    
    smallest_cities = [None, float('inf')]
    for city, reachable in reachable_cities.items():
        if len(reachable) < smallest_cities[1] and len(reachable) >= len(smallest_cities[1]):
            smallest_cities = [city, len(reachable)]
    print(smallest_cities[0])

if __name__ == '__main__':
    main()
This code first reads the graph and the threshold distance from the input, then uses DFS to find all reachable cities within the given threshold. The cities are stored in a dictionary, where the key is the city index and the value is a set of reachable cities. The solution then finds the largest city with the smallest number of reachable neighbors.