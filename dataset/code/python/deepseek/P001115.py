import heapq

def shortest_path(matrix):
    n = len(matrix)
    moves = [(1, 0), (-1, 0), (0, 1), (0, -1), (1, 1), (-1, -1), (1, -1), (-1, 1)]
    heap = [(0, 0, 0)]
    visited = set()
    
    while heap:
        cost, x, y = heapq.heappop(heap)
        if (x, y) == (n-1, n-1):
            return cost
        for move_x, move_y in moves:
            new_x, new_y = x + move_x, y + move_y
            if 0 <= new_x < n and 0 <= new_y < n and matrix[new_x][new_y] == 0 and (new_x, new_y) not in visited:
                visited.add((new_x, new_y))
                heapq.heappush(heap, (cost+1, new_x, new_y))
    return -1

def main():
    n = int(input().strip())
    matrix = [input().strip().split() for _ in range(n)]
    matrix = [[int(cell) for cell in row] for row in matrix]
    print(shortest_path(matrix))

if __name__ == "__main__":
    main()