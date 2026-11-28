Here is the Python code for your problem:

def count_arrangements(N):
    def is_beautiful(n, d):
        return n % d == 0 or d % n == 0

    arrangements = 0
    for i in range(1, N + 1):
        for j in range(i + 1, N + 1):
            if is_beautiful(i, j) or is_beautiful(j, i):
                arrangements += 1
    return arrangements

def main():
    N = int(input().strip())
    print(count_arrangements(N))

if __name__ == "__main__":
    main()

This code first defines a helper function `is_beautiful` that checks if a number `n` is divisible by another number `d`. Then, the `count_arrangements` function counts the number of beautiful arrangements for the numbers 1 to N. The `main` function reads the input and prints the result of `count_arrangements`.