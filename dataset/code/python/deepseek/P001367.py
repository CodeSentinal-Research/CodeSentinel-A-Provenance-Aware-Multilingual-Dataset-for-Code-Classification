Here is the Python code for the problem. It uses the concept of a greedy algorithm to determine the winner of the game.

def matchstick_game():
    N, K = map(int, input().split())
    if N % (2 * K) == 0:
        print("FIRST")
    else:
        print("SECOND")

if __name__ == "__main__":
    matchstick_game()

In this code, we first read the number of matchsticks (N) and the maximum number of matchsticks that can be removed in one turn (K). 

The logic is simple. The first player always tries to maximize the number of matchsticks that can be removed, so we use a greedy strategy where they always remove the least number of matchsticks possible in one turn. 

The reason we only remove the least number of matchsticks possible in one turn is that the first player will always try to remove more matchsticks than the second player can remove in one turn. 

This is why we check if N modulo 2K equals to 0. If N is divisible by 2K (i.e. it is even), the first player will always win because they can always remove more matchsticks than the second player. If N is not divisible by 2K (i.e. it is odd), the first player will always lose.