Here is the Python code for the problem:

def count_collisions(moves):
    collisions = 0
    current_move = moves[0]

    for move in moves[1:]:
        if current_move == move:
            if current_move == 'S':
                collisions += 1
            current_move = 'S'
        elif current_move == 'R' and move == 'R':
            collisions += 1
            current_move = 'S'
        elif current_move == 'L' and move == 'L':
            collisions += 1
            current_move = 'S'

    return collisions


def main():
    n = int(input().strip())
    moves = input().strip()

    print(count_collisions(moves))


if __name__ == "__main__":
    main()

In this code, the `count_collisions` function takes a string of moves as input and returns the number of collisions. It iterates over the moves, checking for collisions based on the current and next move.

The `main` function reads the number of moves and the moves themselves, then calls `count_collisions` to get the number of collisions.