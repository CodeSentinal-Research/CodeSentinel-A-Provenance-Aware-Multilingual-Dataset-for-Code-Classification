Here is the Python code:

def generate_binary_strings(n):
    def backtrack(start, path):
        if len(path) == n:
            print(''.join(path))
            return
        for digit in '01':
            if len(path) >= 2 and start == '0' and digit == '0':
                continue
            path.append(digit)
            backtrack(digit, path)
            path.pop()

    if __name__ == '__main__':
        n = int(input().strip())
        generate_binary_strings(n)


This program generates all binary strings of length N (1 ≤ N ≤ 20) that do not contain two consecutive 1's. The backtrack function is a recursive function that generates all binary strings, and the main function reads the input and calls the backtrack function.

You can run this program in a Python environment and enter the input when prompted.

For example, if you enter 3, the program will generate all possible binary strings of length 3 that do not contain two consecutive 1's.