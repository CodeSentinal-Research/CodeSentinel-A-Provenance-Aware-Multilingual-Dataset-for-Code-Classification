Here is the Python code:

def makesquare(matchsticks):
    total_length = sum(matchsticks)

    if total_length % 4 != 0:
        return False

    matchsticks.sort(reverse=True)

    edge_lengths = [0] * 4

    edge_lengths[0] = matchsticks.pop(0)
    for i in range(1, 4):
        edge_lengths[i] = edge_lengths[i - 1] + matchsticks.pop(0)

    def is_square(a, b, c, d, edge_lengths):
        return a <= edge_lengths[0] and b <= edge_lengths[1] and c <= edge