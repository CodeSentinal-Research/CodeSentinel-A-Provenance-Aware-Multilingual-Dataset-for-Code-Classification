Here is the Python code that solves the problem:

from collections import deque

def minDiceThrows(N, L, ladder, snake):
    ladder = {i: j for i, j in ladder}
    snake = {i: j for i, j in snake}

    visited = [0] * (N + 1)
    parent = [-1] * (N + 1)

    q = deque([1])
    visited[1] = 1

    while q:
        cur = q.popleft()

        if cur == N:
            break

        for i in range(1, 7):
            next_cell = cur + i

            if next_cell > N:
                continue

            if visited[next_cell]:
                continue

            visited[next_cell] = 1
            parent[next_cell] = cur
            q.append(next_cell)

            if next_cell == L:
                return calculateMinDiceThrows(parent, next_cell)

            if next_cell in ladder:
                next_cell = ladder[next_cell]

            if next_cell in snake:
                next_cell = snake[next