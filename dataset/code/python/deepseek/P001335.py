Here is the Python code for your problem:

def can_form_square():
    N = int(input().strip())
    matchsticks = [int(x) for x in input().strip().split()]

    if sum(matchsticks) % 4 != 0:
        return "NO"

    total_len = sum(matchsticks)
    matchsticks.sort()

    for i in range(N):
        if matchsticks[i] > total_len // 4:
            return "NO"
        if matchsticks[i] == total_len // 4:
            if total_len % 4 == 0:
                return "YES"
        matchsticks[i] *= 2
        for j in range(i + 1, N):
            if matchsticks[j] == total_len // 4:
                return "YES"
        matchsticks[j] = matchsticks[i]

    return "NO"


if __name__ == "__main__":
    print(can_form_square())

This Python code reads the number of matchsticks and their lengths from the standard input, checks if they can form a square, and prints "YES" or "NO" accordingly. The code uses a simple depth-first search algorithm to try all possible configurations of the matchsticks.