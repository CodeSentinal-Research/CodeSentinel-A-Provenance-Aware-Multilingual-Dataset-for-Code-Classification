# problem title : Matchsticks to Square
# Solve the stated task using standard input and standard output.
import sys
def can_make_square(matchsticks):
    total = sum(matchsticks)
    if total % 4 != 0 or len(matchsticks) < 4: return False
    side = total // 4
    matchsticks.sort(reverse=True)
    if matchsticks[0] > side: return False
    sides = [0] * 4
    def backtrack(idx):
        if idx == len(matchsticks):
            return sides[0] == sides[1] == sides[2] == sides[3] == side
        for i in range(4):
            if sides[i] + matchsticks[idx] <= side:
                sides[i] += matchsticks[idx]
                if backtrack(idx + 1): return True
                sides[i] -= matchsticks[idx]
            if sides[i] == 0: break
        return False
    return backtrack(0)
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        matchsticks = list(map(int, tokens[1:1+n]))
        print("true" if can_make_square(matchsticks) else "false")
if __name__ == '__main__':
    main()
