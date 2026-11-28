Here is the Python code for the given problem:

def baseball_game_score(n, ops):
    stack = [0]
    for op in ops:
        if op == '+':
            stack.append(stack[-1] + stack[-2])
        elif op == 'C':
            stack.pop()
        elif op == 'D':
            stack.append(2 * stack[-1])
    return sum(stack)

def main():
    n = int(input().strip())
    ops = input().strip().split()
    print(baseball_game_score(n, ops))

if __name__ == '__main__':
    main()

This Python program first defines a function `baseball_game_score` that takes a list of operations as input and returns the total score. Then, in the `main` function, it reads the number of operations `n` and the operations themselves `ops`. Finally, it calls the `baseball_game_score` function with these values.