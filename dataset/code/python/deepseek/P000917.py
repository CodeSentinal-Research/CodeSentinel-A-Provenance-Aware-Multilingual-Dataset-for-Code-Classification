Here is a Python code that uses the binomial coefficient formula (n choose k) to calculate the number of valid distributions.

import math

def solve(N, K):
    return math.comb(N, K)

def main():
    N, K = map(int, input().split())
    print(solve(N, K))

if __name__ == "__main__":
    main()

This code first defines a function `solve` that uses the `comb` function from the `math` module to calculate the number of valid distributions. The `comb` function calculates the number of ways to choose `k` elements from a set of `n` elements.

The `main` function then takes the number of balls and boxes from the user and prints the result of calling `solve` with these values.

Please note that the input will be a space-separated string of two integers. If you want to handle cases where the user might not provide two integers, you can modify the `main` function to read the input as a single line and split the line into two integers using `input().split()`.