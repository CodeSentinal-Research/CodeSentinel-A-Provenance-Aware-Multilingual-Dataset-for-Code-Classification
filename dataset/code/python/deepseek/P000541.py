def orangesRotting(grid):
    fresh = 0
    rotten = set()
    directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 1: 
                fresh += 1
            elif grid[i][j] == 2: 
                rotten.add((i, j))
    
    if fresh == 0: 
        return 0
    
    minutes = 0
    while rotten:
        rotten_next = set()
        for r in rotten:
            for d in directions:
                x, y = r[0] + d[0], r[1] + d[1]
                if 0 <= x < len(grid) and 0 <= y < len(grid[0]) and grid[x][y] == 1:
                    fresh -= 1
                    grid[x][y] = 2
                    rotten_next.add((x, y))
        rotten = rotten_next
        minutes += 1
    
    if fresh == 0: 
        return minutes - 1
    else: 
        return -1

def main():
    m = int(input())
    n = int(input())
    grid = [[int(cell) for cell in input().split()] for _ in range(m)]
    print(orangesRotting(grid))

if __name__ == "__main__":
    main()

In this Python solution, we first count the number of fresh oranges and rotten oranges. Then we use BFS to find the time it takes for all rotten oranges to become rotten. If there are still fresh oranges left, we can't make all oranges rotten in this time since some oranges can't be rotten. In this case, we return -1. Otherwise, we return the minimum time needed.