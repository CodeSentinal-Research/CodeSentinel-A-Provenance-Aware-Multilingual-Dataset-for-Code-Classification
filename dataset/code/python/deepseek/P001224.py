Here's the Python code:

def count_ways(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return count_ways(n-1) + count_ways(n-2)

def main():
    n = int(input())
    print(count_ways(n))

if __name__ == "__main__":
    main()

In this code, the `count_ways` function calculates the number of ways to tile a 2×N board by considering the 2×1 dominoes. If the board size is 0, there are 0 ways to tile, if the board size is 1, there are 1 way to tile. For larger board sizes, the number of ways to tile the board is the sum of the number of ways to tile the smaller board (n-1) and the smaller board's ways to tile the board (n-2).

The `main` function reads the input and calls the `count_ways` function to get the number of ways to tile the board. It also handles the input and output for the user.