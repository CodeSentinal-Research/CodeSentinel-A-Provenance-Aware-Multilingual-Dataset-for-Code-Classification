Here is a Python solution using Breadth-First Search (BFS) algorithm:

from collections import deque

def snakesAndLadders(board):
    n = len(board)
    visited = [False] * (n+1)
    moves = [0] * (n+1)
    queue = deque([1])
    visited[1] = True
    
    while queue:
        player = queue.popleft()
        for nextPlayer in range(player+1, min(player+7, n+1)):
            if not visited[nextPlayer]:
                if board[nextPlayer] != -1:
                    nextPosition = board[nextPlayer]
                    moves[nextPlayer] = moves[player] + 1
                    if nextPosition == n*n:
                        return moves[nextPlayer]
                    queue.append(nextPlayer)
                    visited[nextPlayer] = True
                elif board[nextPlayer] == -1:
                    moves[nextPlayer] = moves[player] + 1
                    if nextPlayer == n*n:
                        return moves[nextPlayer]
                    queue.append(nextPlayer)
                    visited[nextPlayer] = True

    return -1

This code uses BFS to find the minimum number of moves to reach the final square from any given square on the board. It starts from square 1 and tries to move to the next squares by rolling a six-sided die until it lands on a new square. If the new square has a snake or ladder, it immediately moves to the destination. If it lands on the start of a ladder or the head of a snake, it moves to its destination. The function returns the minimum number of moves if it is possible, or -1 if it is not.

The input to this function is an n × n board, where each element of the board is an integer between 0 and n*n (inclusive), or -1 for empty square. The board is defined in the problem statement.

Please note that this code assumes that the board is well-formed, i.e., each element is either the start of a ladder or the head of a snake, or -1 for an empty square.