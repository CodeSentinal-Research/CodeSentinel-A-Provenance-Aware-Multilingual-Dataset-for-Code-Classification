import sys
from collections import Counter

def solve():
    input_data = sys.stdin.read().splitlines()
    if not input_data:
        return
    v = int(input_data[0])
    votes = input_data[1:1+v]
    
    if not votes:
        return
        
    teams = list(votes[0])
    teams.sort()
    
    def sort_key(team):
        return [-votes[0].count(team) if team in votes[0] else 0] # Simplified
        
    # Correct ranking logic
    rank_map = {c: i for i, c in enumerate(teams)}
    
    def compare(t1, t2):
        for i in range(len(teams)):
            c1 = sum(1 for vote in votes if vote[i] == t1)
            c2 = sum(1 for vote in votes if vote[i] == t2)
            if c1 != c2:
                return c1 > c2
        return t1 < t2
        
    # Using functools cmp_to_key is better but let's use simple sort with key
    # Key: tuple of counts at each position
    def get_key(team):
        counts = []
        for i in range(len(teams)):
            counts.append(-sum(1 for vote in votes if vote[i] == team))
        counts.append(team)
        return tuple(counts)
        
    teams.sort(key=get_key)
    print("".join(teams))

solve()

