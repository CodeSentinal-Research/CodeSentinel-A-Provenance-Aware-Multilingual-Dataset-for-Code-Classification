Here is a Python code that uses Depth-First Search (DFS) to solve the problem:

def can_finish_courses(n, m, pairs):
    adj_list = [[] for _ in range(n + 1)]

    prerequisites = [[] for _ in range(n + 1)]

    visited = [0 for _ in range(n + 1)]

    dfs_visited = [0 for _ in range(n + 1)]

    for pair in pairs:
        u, v = pair[0], pair[1]
        adj_list[u].append(v)
        prerequisites[v].append(u)

    for i in range(1, n + 1):
        if visited[i] == 0:
            if dfs_cycle(i, adj_list, visited, dfs_visited):
                return False

    return True


def dfs_cycle(node, adj_list, visited, dfs_visited):
    visited[node] = 1

    dfs_visited[node] = 1

    for neighbour in adj_list[node]:
        if visited[neighbour] == 0:
            if dfs_cycle(neighbour, adj_list, visited, dfs_visited):
                return True
        elif dfs_visited[neighbour] == 1:
            return True

    dfs_visited[node] = 0

    return False


def main():
    n, m = map(int, input().split())
    pairs = []
    for _ in range(m):
        pair = list(map(int, input().split()))
        pairs.append(pair)
    if can_finish_courses(n, m, pairs):
        print("YES")
    else:
        print("NO")


if __name__ == "__main__":
    main()
This code firstly creates an adjacency list and a prerequisite graph from the input. Then it uses DFS to check if there is a cycle in the graph. If there is a cycle, it means there is a cycle in the prerequisites, and we can't finish all the courses, so we print "NO". Otherwise, we can finish all the courses, so we print "YES".