def wallsAndGates(rooms):
    m, n = len(rooms), len(rooms[0])
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    
    queue = collections.deque()
    
    for i in range(m):
        for j in range(n):
            if rooms[i][j] == 0:
                queue.append((i, j))
    
    while queue:
        i, j = queue.popleft()
        for di, dj in directions:
            ni, nj = i + di, j + dj
            if 0 <= ni < m and 0 <= nj < n and rooms[ni][nj] > rooms[i][j] + 1:
                rooms[ni][nj] = rooms[i][j] + 1
                queue.append((ni, nj))

In the above Python solution, we start by obtaining the dimensions of the grid. Then, we initialize a queue to perform Breadth First Search (BFS). We then iterate through the grid and find all gates. We add all gates to the queue.

Afterwards, we enter the BFS loop. In each iteration, we check all four possible movements from the current cell. If it is not a wall and if the current cell is not reachable from the current cell by using the current gate, we update the distance from the current cell to the gate and add the new cell to the queue.

Finally, we return the updated grid.