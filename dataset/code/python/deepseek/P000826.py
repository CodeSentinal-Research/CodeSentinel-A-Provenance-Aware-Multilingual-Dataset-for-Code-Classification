Here is the Python code for the problem:

def arrange_coins(n):
    i = 1
    count = 0
    while n > 0:
        n -= i
        i += 1
        count += 1
    return count

def main():
    n = int(input("Enter the number of coins: "))
    print("Number of complete staircase rows: ", arrange_coins(n))

if __name__ == "__main__":
    main()

This code defines a function `arrange_coins(n)` which calculates the number of staircase rows that can be formed using `n` coins. It does this by continuously subtracting the current row number `i` from `n`, and increments `i` by 1 each time, until `n` becomes 0. The function then returns the count of rows.

In the `main()` function, it takes an input `n` from user and calls the `arrange_coins(n)` function to get the number of complete rows.

The `main()` function is the entry point of the program and it is always executed when the script is run.