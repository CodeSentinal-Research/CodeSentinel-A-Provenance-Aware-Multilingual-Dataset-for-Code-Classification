Here is the Python code for the problem:

def countWays(n):
   if n <= 1:
       return n
   else:
       return countWays(n-1) + countWays(n-2)

n = int(input("Enter the value of N: "))
print(countWays(n))
In this code, we are defining a function countWays that takes an integer n as input and returns the total number of ways to reach the n-th step. The function uses recursion to calculate the number of ways. If n is less than or equal to 1, it returns n itself. Otherwise, it returns the sum of the number of ways to reach the (n-1)-th and (n-2)-th steps.

The main function is a simple input handling part. It gets an input n from the user, calls the countWays function with n as the argument, and prints the result.