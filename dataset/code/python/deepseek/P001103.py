import sys
from collections import defaultdict, deque

class Server:
    def __init__(self, id):
        self.id = id
        self.connected_to = set()
        self.connections = set()

    def connect(self, server):
        self.connected_to.add(server)
        server.connected_to.add(self)

def build_graph(servers, edges):
    graph = defaultdict(set)
    for u, v in edges:
        graph[u].add(v)
        graph[v].add(u)
    return graph

def bfs(graph, source):
    distances = {server: float('inf') for server in graph}
    distances[source] = 0
    parent = {server: None for server in graph}
    queue = deque([server for server in graph])

    while queue:
        current_server = queue.popleft()
        for neighbour in graph[current_server]:
            if distances[current_server] + 1 < distances[neighbour]:
                distances[neighbour] = distances[current_server] + 1
                parent[neighbour] = current_server
                queue.append(neighbour)

    return {server: distance for server, distance in distances.items() if distance != float('inf')}

def find_critical_connections(graph, servers):
    output = []
    distance_dict = bfs(graph, servers[0])
    for server_id, distance in distance_dict.items():
        if distance == float('inf'):
            continue
        for server in servers:
            if server.id == server_id:
                for neighbour in server.connected_to:
                    if distance_dict[neighbour] == distance:
                        output.append((server.id, neighbour))
                        break
    return output

def main():
    N, M = map(int, sys.stdin.readline().split())
    servers = [Server(i) for i in range(N)]
    edges = []
    for _ in range(M):
        u, v = map(int, sys.stdin.readline().split())
        edges.append((u-1, v-1))
        servers[u-1].connect(servers[v-1])

    graph = build_graph(servers, edges)
    critical_connections = find_critical_connections(graph, servers)

    if not critical_connections:
        print('NONE')
    else:
        for server_id, neighbour in sorted(critical_connections):
            print(f'{server_id} {neighbour}')

if __name__ == "__main__":
    main()