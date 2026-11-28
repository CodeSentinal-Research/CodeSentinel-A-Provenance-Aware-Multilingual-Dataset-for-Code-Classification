Here is a Python solution that uses Union-Find to solve the problem. The Union-Find data structure is an efficient data structure that supports operations on sets.

class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n+1))
        self.rank = [0] * (n+1)

    def find_set(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find_set(self.parent[x])
        return self.parent[x]

    def union_set(self, x, y):
        x_set, y_set = self.find_set(x), self.find_set(y)
        if x_set != y_set:
            if self.rank[x_set] < self.rank[y_set]:
                x_set, y_set = y_set, x_set
            self.parent[y_set] = x_set
            if self.rank[x_set] == self.rank[y_set]:
                self.rank[x_set] += 1

def solve():
    n, q = map(int, input().split())
    uf = UnionFind(n)
    for _ in range(q):
        operation = input().split()
        if operation[0] == 'I':
            uf.union_set(int(operation[1]), int(operation[2]))
        else:
            print('YES' if uf.find_set(int(operation[1])) == uf.find_set(int(operation[2])) else 'NO')

if __name__ == "__main__":
    solve()

This code first reads the number of vertices N and queries Q from the input. Then, it creates a UnionFind instance and for each operation, it performs the union operation if the operation is an add edge operation, and the find operation if the operation is a connectivity query. The result is printed in the end.