Here's a Python solution for the problem:

def find_players():
    M = int(input().strip())
    players_won = {}
    players_lost = {}
    for _ in range(M):
        winner, loser = map(int, input().strip().split())
        if winner in players_won:
            players_won[winner] += 1
        else:
            players_won[winner] = 1
        if loser in players_lost:
            players_lost[loser] += 1
        else:
            players_lost[loser] = 1
    players_zero_loss = sorted(k for k, v in players_lost.items() if v == 0)
    print(' '.join(map(str, players_zero_loss)))
    players_one_loss = sorted(k for k, v in players_lost.items() if v == 1)
    print(' '.join(map(str, players_one_loss)))

find_players()

This code first reads the number of matches. Then, for each match, it reads the winner and loser, and updates the player stats accordingly. After all matches have been processed, it prints the players who never lost, and the players who lost exactly once. It uses the `sorted` function to sort the players in ascending order.