Here is the Python code for your problem:

def find_sum(n):
    return n * (n + 1) // 2

n = int(input("Enter a positive integer: "))

if 1 <= n <= 10**9:
    print("The sum of first", n, "natural numbers is", find_sum(n))
else:
    print("Invalid input! Please enter a positive integer between 1 and 10^9.")