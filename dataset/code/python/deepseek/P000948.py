Here is a simple Python solution for your problem. The game is played on a chessboard, where the token is initially at position (x, y). On each turn, the player can move the token to one of the allowed positions defined by the game's movement rules. If the player can't make a move, the game ends and the player loses. If the starting player has a winning strategy, the program will print "First", otherwise, it will print "Second".

def is_winning_move(N, x, y):
    if (x + y) % 2 == 0:
        return True
    elif x >= y and y <= N-x-1:
        return True
    elif x <= y and y <= N-x-1:
        return True
    elif y >= x and x <= N-y-1:
        return True
    return False

def main():
    N = int(input("Enter the value of N: "))
    x, y = map(int, input("Enter the starting coordinates (x, y): ").split())
    if is_winning_move(N, x, y):
        print("First")
    else:
        print("Second")

if __name__ == "__main__":
    main()
This code will prompt the user to enter the value of N and the starting coordinates (x, y), and then it will check if the starting player has a winning strategy. It uses a function `is_winning_move()` to check if the starting player can win. The function `is_winning_move()` returns True if the starting player can win, and False otherwise.