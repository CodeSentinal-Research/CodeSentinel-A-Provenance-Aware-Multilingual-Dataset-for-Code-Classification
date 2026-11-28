import sys

def generate_parenthesis(n: int):
    result = []
    def backtrack(curr, open_count, close_count):
        if len(curr) == 2 * n:
            result.append(curr)
            return
        if open_count < n:
            backtrack(curr + '(', open_count + 1, close_count)
        if close_count < open_count:
            backtrack(curr + ')', open_count, close_count + 1)
    backtrack('', 0, 0)
    return result

def main():
    input_data = sys.stdin.read().split()
    if input_data:
        n = int(input_data[0])
        for s in generate_parenthesis(n):
            print(s)

if __name__ == '__main__':
    main()