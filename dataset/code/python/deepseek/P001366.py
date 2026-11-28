def find_unique_paths(R, C, grid, start, end):
    visited = set()

    def dfs(r, c, count):
        if r == end[0] and c == end[1]:
            return 1 if count == R else 0

        if not (0 <= r < R and 0 <= c < C) or grid[r][c] == '#' or (r, c) in visited:
            return 0

        visited.add((r, c))

        paths = dfs(r + 1, c, count + 1) + dfs(r - 1, c, count + 1) + dfs(r, c + 1, count + 1) + dfs(r, c - 1, count + 1)

        visited.remove((r, c))

        return paths

    return dfs(start[0], start[1], 0)


def main():
    R, C = map(int, input().split())
    grid = [input().split() for _ in range(R)]
    start = list(map(lambda x: (int(x[0]), int(x[1])) , input().split()))
    end = list(map(lambda x: (int(x[0]), int(x[1])) , input().split()))
    print(find_unique_paths(R, C, grid, start, end))


if __name__ == "__main__":
    main()