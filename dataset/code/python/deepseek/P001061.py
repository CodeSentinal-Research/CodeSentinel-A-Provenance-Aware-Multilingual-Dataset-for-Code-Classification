Here's the Python code to solve the problem:

from collections import defaultdict

def detect_cycle(graph, start, visited, rec_stack):
    visited[start] = True
    rec_stack[start] = True

    for neighbor in graph[start]:
        if not visited[neighbor]:
            if detect_cycle(graph, neighbor, visited, rec_stack):
                return True
        elif rec_stack[neighbor]:
            return True

    rec_stack[start] = False
    return False

def main():
    N, M = map(int, input().split())
    graph = defaultdict(list)

    for _ in range(M):
        u, v = map(int, input().split())
        graph[u-1].append(v-1)

    visited = [False] * N
    rec_stack = [False] * N

    for node in range(N):
        if not visited[node]:
            if detect_cycle(graph, node, visited, rec_stack):
                print('YES')
                return

    print('NO')

if __name__ == '__main__':
    main()
This program first reads the number of vertices and edges from the input. Then, it reads the edges and forms a graph. The `detect_cycle` function is a recursive function that checks if the graph contains a cycle from a given node. The `main` function then checks all nodes to see if there is a cycle. If there is, it prints 'YES'. If not, it prints 'NO'.