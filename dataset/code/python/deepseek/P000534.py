The problem is essentially a simulation of a Dota2 game where senators from different parties act in a round-robin manner. A senator who still has voting rights may ban a senator from the opposing party. The party who can only win when all senators are banned wins.

Here is a Python solution using a priority queue to handle the simulation:

import collections
import re

def predictPartyVictory(senate):
    queue = collections.deque()
    bans = collections.deque()
    r_bans, d_bans = 0, 0

    for s in senate:
        if s == 'R':
            r_bans += 1
        else:
            d_bans += 1
        queue.append(s)
        bans.append(0)

    while r_bans and d_bans:
        s = queue.popleft()
        if bans[0] == 0:
            if s == 'R':
                r_bans -= 1
            else:
                d_bans -= 1
            bans.popleft()
        else:
            bans.popleft()

    return "Radiant" if r_bans == 0 else "Dire"

print(predictPartyVictory("RD"))  
print(predictPartyVictory("RDR"))  

In the above code, we first create two deque `queue` and `bans`. `queue` is a deque of senators and `bans` is a deque of their bans. We iterate through each senator in the given `senate` and count the number of senators of each party (`R` and `D`).

Then we start a while loop that continues until all senators of one party have been banned (`r_bans` and `d_bans` both become 0). Inside the loop, we remove a senator from the `queue` and if it is not a ban, we add it to the `bans` queue. Otherwise, we add it to the `bans` queue and then remove it from the `queue`.

Finally, after the while loop ends, if `r_bans` is not 0, we return "Radiant" because there are still senators of the Radiant party. Otherwise, we return "Dire" because all senators of the Dire party have been banned.

This solution assumes that every senator acts optimally for its party, which means they always try to ban a senator from the other party.