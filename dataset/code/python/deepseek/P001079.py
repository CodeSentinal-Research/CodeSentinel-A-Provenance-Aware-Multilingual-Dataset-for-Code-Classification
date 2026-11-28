Sure, here is the Python code for the problem:

import sys
sys.stdin = open('input.txt', 'r')

def find_bridges(graph, start, visited, low, disc):
    visited[start] = True
    low[start] = disc[start] = time
    time += 1

    for neighbour in graph[start]:
        if visited[neighbour] == False:
            find_bridges(graph, neighbour, visited, low, disc)
            low[start] = min(low[start], low[neighbour])
            if low[neighbour] > disc[start]:
                print(start, 'to', neighbour)
        elif visited[neighbour] == True:
            low[start] = min(low[start], disc[neighbour])

def main():
    global time
    time = 0
    n, m = map(int, input().split())
    graph = [[] for i in range(n)]
    for _ in range(m):
        u, v = map(int, input().split())
        graph[u].append(v)
        graph[v].append(u)
    visited = [False]*n
    low = [inf]*n
    disc = [inf]*n
    for i in range(n):
        if visited[i] == False:
            find_bridges(graph, i, visited, low, disc)

if __name__ == '__main__':
    main()

In this code, we're first defining a global variable `time` which is used to keep track of the current time. In the `main` function, we're reading the number of nodes and edges from the input, and then creating a graph from these inputs. Then we're using a depth-first search to find all the bridges in the graph.

The `find_bridges` function is responsible for finding all the bridges in a subgraph. It uses a depth-first search to find all the nodes in the subgraph and their `disc` and `low` values. If the current node is not visited, we recursively call `find_bridges` for the current node and all its neighbours. If the current node is visited, we update the `low` and `disc` values for the current node. If the `low` value of a neighbour is greater than or equal to the `disc` value of the current node, it means that the current node is a bridge.