Here is the Python code with main function and input handling:

def min_bit_flips(start, goal):
    flips = 0
    while start != goal:
        flips += 1
        start = start ^ 1
        temp = start
        start = goal
        goal = temp
    return flips


def main():
    start = int(input("Enter start: "))
    goal = int(input("Enter goal: "))
    print("Minimum Bit Flips: ", min_bit_flips(start, goal))


if __name__ == "__main__":
    main()

In the code above, `min_bit_flips` function calculates the minimum bit flips to convert `start` into `goal`. The function uses the bitwise XOR operator to determine the difference between `start` and `goal`. Then, the `start` and `goal` are swapped, and the process is repeated until `start` equals `goal`, at which point the minimum number of flips is returned.

The `main` function is used to get the inputs for `start` and `goal`, and then call the `min_bit_flips` function.