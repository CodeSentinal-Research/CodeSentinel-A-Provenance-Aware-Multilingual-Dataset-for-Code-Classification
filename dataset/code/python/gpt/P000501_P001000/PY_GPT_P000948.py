# problem title : Chessboard Game
# Solve the stated task using standard input and standard output.
def chessboard_game(x: int, y: int) -> str:
    x = (x - 1) % 4
    y = (y - 1) % 4
    if (x == 0 or x == 1) and (y == 0 or y == 1):
        return "Second"
    return "First"

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        x, y = map(int, input().split())
        print(chessboard_game(x, y))
