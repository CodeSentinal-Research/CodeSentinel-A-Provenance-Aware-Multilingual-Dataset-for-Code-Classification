Here is the Python code:

def tribonacci(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    elif n == 2:
        return 1

    a, b, c = 0, 1, 1
    for _ in range(3, n+1):
        a, b, c = b, c, a+b+c

    return c

n = int(input())
print(tribonacci(n))

This program defines the function `tribonacci(n)`, which calculates the nth number in the Tribonacci sequence using dynamic programming. It first handles the base cases (0, 1, 2), then it uses a loop to calculate the remaining numbers. The loop uses a three-variable iteration (a, b, c), and the loop updates a, b, and c for the next iteration. In each iteration, the current number is calculated as the sum of the previous three numbers.

The main part of the program reads an integer from the user, calls the function with this integer as argument, and then prints the result.