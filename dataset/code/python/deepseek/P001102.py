Here's the Python code for the problem:

import sys

def minCost(n, m, roads):
    parent = list(range(n+1))  
    cost = [0] * (n+1)  

    roads.sort(key=lambda x: x[2])

    for u, v, cost in roads:
        if find(u, parent) == find(v, parent):
            continue

        union(u, v, parent, cost, cost[u], cost[v])

    total_cost = sum(cost[i] for i in range(1, n+1))

    if find(0, parent) != 0:
        return -1

    return total_cost

def find(x, parent):
    if parent[x] != x:
        parent[x] = find(parent[x], parent)
    return parent[x]

def union(x, y, parent, cost, c1, c2):
    px, py = find(x, parent), find(y, parent)

    if c1 < c2:
        parent[py] = px
        cost[px] += c1
    else:
        parent[px] = py
        cost[py] += c2

def main():
    n, m = map(int, sys.stdin.readline().split())
    roads = []
    for _ in range(m):
        u, v, cost = map(int, sys.stdin.readline().split())
        roads.append((u-1, v-1, cost))  
    print(minCost(n, m, roads))

if __name__ == "__main__":
    main()

This code first reads the number of cities `N` and roads `M`. Then, for each road, it reads the two cities and the cost of connecting them. The roads are sorted by their costs.

The `minCost` function implements the Kruskal's algorithm to find the minimum spanning tree. It first initializes the `parent` list to represent the connected component structure. The `cost` list is used to store the cost of each city when it is connected.

The `find` function finds the representative of the connected component that a city belongs to, and makes the path compression optimization to ensure that `find` always return the root of the component.

The `union` function unites two cities into the same component. It first finds the representative of both cities, and then unites them into the same component. If one city is connected with the cost is smaller, then the cost of the road is added to the cost of the city.

In the main function, the `minCost` function is called, and the result is printed.