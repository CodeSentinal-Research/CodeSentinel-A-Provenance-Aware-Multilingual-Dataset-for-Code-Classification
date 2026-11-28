Here's a Python solution that can solve the cryptarithmetic puzzle using backtracking:

def solve_puzzle(words, eqn, assignments, digit='1', start=0):
    if start == len(words):
        if eqn == ''.join(assignments[i][j] for i, j in zip(words, assignments)):
            return True
        return False

    if start == len(words[start]):
        if solve_puzzle(words, eqn, assignments, digit, start+1):
            return True
        else:
            assignments[start][digit] = ''
        return False

    for char in '23456789':
        if all(char not in words[i] for i in range(start+1, len(words))):
            assignments[start][digit] = char
            if solve_puzzle(words, eqn, assignments, char, start+1):
                return True
            assignments[start][digit] = ''
    return False


def cryptarithmetic_puzzle(words, eqn):
    assignments = [dict() for _ in words]
    if not solve_puzzle(words, eqn, assignments):
        print('IMPOSSIBLE')


if __name__ == "__main__":
    words = ['PERSIST', 'INTEL', 'WORLD']
    eqn = 'INTEL - PERSIST + WORLD = 128'
    cryptarithmetic_puzzle(words, eqn)

This code first defines a function `solve_puzzle` that uses backtracking to solve the puzzle. This function recursively tries to assign digits to the letters in the words. If it can't find a solution, it unassigns the digit and tries the next one.

The function `cryptarithmetic_puzzle` creates a list of empty dictionaries to represent the assignments. Then it calls `solve_puzzle` and prints 'IMPOSSIBLE' if it can't find a solution.

The `main` function tests the `cryptarithmetic_puzzle` function with a sample input.