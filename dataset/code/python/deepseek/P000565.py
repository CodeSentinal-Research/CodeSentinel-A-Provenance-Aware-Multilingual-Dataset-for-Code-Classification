Here is the Python code:

def matrix_cells_in_distance_order(rows, cols, rCenter, cCenter):
    matrix = [[0 for _ in range(cols)] for _ in range(rows)]

    visited = set()

    queue = [(rCenter, cCenter)]

    while queue:
        r, c = queue.pop(0)

        if r < 0 or c < 0 or r >= rows or c >= cols or (r, c) in visited:
            continue

        visited.add((r, c))

        matrix[r][c] = (r, c)

        for nr, nc in [(r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1)]:
            queue.append((nr, nc))

    return sorted(matrix[r][c] for r in range(rows) for c in range(cols))

And here is the main function:

def main():
    rows = 5
    cols = 5
    rCenter = 2
    cCenter = 2
    result = matrix_cells_in_distance_order(rows, cols, rCenter, cCenter)
    print(result)

if __name__ == "__main__":
    main()

This code creates a matrix filled with zeros, then uses a Breadth-First Search (BFS) algorithm to fill in the matrix cells. The cells are visited in the order of their Manhattan distance from the start cell, and the result is returned as a list of cell coordinates.