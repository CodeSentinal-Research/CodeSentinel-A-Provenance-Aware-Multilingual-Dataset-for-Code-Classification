import sys
from collections import defaultdict

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    m = int(input_data[idx]); idx += 1
    
    wins = defaultdict(int)
    losses = defaultdict(int)
    players = set()
    
    for _ in range(m):
        w = int(input_data[idx]); idx += 1
        l = int(input_data[idx]); idx += 1
        wins[w] += 1
        losses[l] += 1
        players.add(w)
        players.add(l)
        
    zero_loss = sorted([p for p in players if losses[p] == 0])
    one_loss = sorted([p for p in players if losses[p] == 1])
    
    print(*zero_loss)
    print(*one_loss)

solve()

