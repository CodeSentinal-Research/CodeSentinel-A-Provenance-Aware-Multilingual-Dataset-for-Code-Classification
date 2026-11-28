Here is a simple Python solution for the problem:

def calculate_height():
    N = int(input())
    height = 0
    while N > 0:
        N //= 2
        height += 1
    print(height)

calculate_height()

This program reads the input number of nodes, calculates the height of the heap by dividing the input by 2 at each iteration until the number of nodes becomes zero, and then prints the height.