Here is the Python code:

def solve(n, maxHeights):
    maxHeights.sort(reverse=True)
    total = 0
    for i in range(n):
        total += maxHeights[i] * (i+1)
    return total

def main():
    n = int(input().strip())
    maxHeights = list(map(int, input().strip().split()))
    print(solve(n, maxHeights))

main()

In this code, the function `solve` first sorts the `maxHeights` array in descending order. It then calculates the sum of the products of each tower's height and its index (which represents the tower's position from the peak) and stores it in the variable `total`. The `main` function reads the number of towers (`n`), reads the maximum allowed height of each tower (`maxHeights`), and then calls the `solve` function. The `main` function only needs to be called if the problem is run as a standalone script, with `main()` being the entry point for the program.