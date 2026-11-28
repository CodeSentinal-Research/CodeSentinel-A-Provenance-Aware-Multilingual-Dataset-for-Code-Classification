import sys
def solve():
    s = sys.stdin.read().split()[0]
    memo = {}
    def can_win(state):
        if state in memo: return memo[state]
        for i in range(len(state) - 1):
            if state[i] == '+' and state[i+1] == '+':
                next_state = state[:i] + '--' + state[i+2:]
                if not can_win(next_state):
                    memo[state] = True
                    return True
        memo[state] = False
        return False
    print("true" if can_win(s) else "false")
solve()
